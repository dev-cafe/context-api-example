module example

    use, intrinsic :: iso_c_binding, only: c_double, c_ptr

    implicit none

    private

    public example_new
    public example_free
    public example_deposit
    public example_withdraw
    public example_get_balance

    type :: account
        private
        real(c_double) :: balance
        ! it is possible to have allocatable arrays here
    end type

    logical :: is_initialized = .false.

contains

    type(c_ptr) function example_new() bind (c)
        use, intrinsic :: iso_c_binding, only: c_loc
        type(account), pointer :: f_context
        type(c_ptr) :: context

        allocate(f_context)
        context = c_loc(f_context)
        example_new = context
        f_context%balance = 0.0d0
        is_initialized = .true.
    end function

    subroutine example_free(context) bind (c)
        use, intrinsic :: iso_c_binding, only: c_f_pointer
        type(c_ptr), value :: context
        type(account), pointer :: f_context

        call c_f_pointer(context, f_context)
        f_context%balance = 0.0d0
        deallocate(f_context)
        is_initialized = .false.
    end subroutine

    subroutine stop_if_uninitialized()
        if (.not. is_initialized) then
            print *, 'ERROR: context is not initialized'
            stop 1
        end if
    end subroutine

    subroutine example_deposit(context, f) bind (c)
        use, intrinsic :: iso_c_binding, only: c_f_pointer
        type(c_ptr), value :: context
        real(c_double), value :: f
        type(account), pointer :: f_context

        call stop_if_uninitialized()
        call c_f_pointer(context, f_context)
        f_context%balance = f_context%balance + f
    end subroutine

    subroutine example_withdraw(context, f) bind (c)
        type(c_ptr), value :: context
        real(c_double), value :: f

        call stop_if_uninitialized()
        call example_deposit(context, -f)
    end subroutine

    real(c_double) function example_get_balance(context) bind (c)
        use, intrinsic :: iso_c_binding, only: c_f_pointer
        type(c_ptr), value, intent(in) :: context
        type(account), pointer :: f_context

        call stop_if_uninitialized()
        call c_f_pointer(context, f_context)
        example_get_balance = f_context%balance
    end function

end module
