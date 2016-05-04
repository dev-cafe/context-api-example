module example

    use, intrinsic :: iso_c_binding, only: c_double, c_ptr

    implicit none

    private

    public example_new
    public example_free
    public example_deposit
    public example_withdraw
    public example_get_balance
    public example_print_history

    type :: account
        private
        real(c_double), allocatable :: history(:)
    end type

contains

    type(c_ptr) function example_new() bind (c)
        use, intrinsic :: iso_c_binding, only: c_loc
        type(account), pointer :: f_context
        type(c_ptr) :: context

        allocate(f_context)
        context = c_loc(f_context)
        example_new = context
    end function

    subroutine example_free(context) bind (c)
        use, intrinsic :: iso_c_binding, only: c_f_pointer
        type(c_ptr), value :: context
        type(account), pointer :: f_context

        call c_f_pointer(context, f_context)
        deallocate(f_context%history)
        deallocate(f_context)
    end subroutine

    subroutine example_deposit(context, f) bind (c)
        use, intrinsic :: iso_c_binding, only: c_f_pointer
        type(c_ptr), value :: context
        real(c_double), value :: f
        type(account), pointer :: f_context

        call c_f_pointer(context, f_context)
        call append(f_context%history, f)
    end subroutine

    subroutine example_withdraw(context, f) bind (c)
        type(c_ptr), value :: context
        real(c_double), value :: f

        call example_deposit(context, -f)
    end subroutine

    real(c_double) function example_get_balance(context) bind (c)
        use, intrinsic :: iso_c_binding, only: c_f_pointer
        type(c_ptr), value :: context
        type(account), pointer :: f_context

        call c_f_pointer(context, f_context)
        example_get_balance = sum(f_context%history)
    end function

    subroutine example_print_history(context) bind (c)
        use, intrinsic :: iso_c_binding, only: c_f_pointer
        type(c_ptr), value :: context
        type(account), pointer :: f_context
        integer :: i

        call c_f_pointer(context, f_context)
        print *, 'transaction history:'
        do i = 1, size(f_context%history)
            print *, f_context%history(i)
        end do
    end subroutine

    subroutine append(v, f)
        ! this is not an efficient way of doing this
        ! but it does not matter for this example
        real(c_double), allocatable :: v(:)
        real(c_double), intent(in) :: f
        real(c_double), allocatable :: v_local(:)

        if (allocated(v)) then
            allocate(v_local(size(v) + 1))
            v_local(1:size(v)) = v
            v_local(size(v) + 1) = f
            call move_alloc(v_local, v)
        else
            allocate(v(1))
            v(1) = f
        end if
    end subroutine

end module
