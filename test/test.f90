module example_interface

    use, intrinsic :: iso_c_binding, only: c_ptr, c_double

    implicit none

    public example_new
    public example_free
    public example_deposit
    public example_withdraw
    public example_get_balance

    private

    interface example_new
        function example_new() result(context) bind (c)
            import :: c_ptr
            type(c_ptr) :: context
        end function
    end interface

    interface example_free
        subroutine example_free(context) bind (c)
            import :: c_ptr
            type(c_ptr), value :: context
        end subroutine
    end interface

    interface example_deposit
        subroutine example_deposit(context, f) bind (c)
            import :: c_ptr, c_double
            type(c_ptr), value :: context
            real(c_double), value, intent(in) :: f
        end subroutine
    end interface

    interface example_withdraw
        subroutine example_withdraw(context, f) bind (c)
            import :: c_ptr, c_double
            type(c_ptr), value :: context
            real(c_double), value, intent(in) :: f
        end subroutine
    end interface

    interface example_get_balance
        function example_get_balance(context) result(r) bind (c)
            import :: c_ptr, c_double
            type(c_ptr), value, intent(in) :: context
            real(c_double) :: r
        end function
    end interface

end module


program test

    use example_interface, only: example_new, &
                                 example_free, &
                                 example_deposit, &
                                 example_withdraw, &
                                 example_get_balance

    use, intrinsic :: iso_c_binding, only: c_ptr

    implicit none

    type(c_ptr) :: account1
    type(c_ptr) :: account2

    account1 = example_new()

    call example_deposit(account1, 100.0d0)
    call example_deposit(account1, 100.0d0)

    account2 = example_new()

    call example_deposit(account2, 200.0d0)
    call example_deposit(account2, 200.0d0)

    call example_withdraw(account1, 50.0d0)

    if (example_get_balance(account1) /= 150.0d0) then
        print *, "unexpected balance on account1"
        stop 1
    end if
    call example_free(account1)

    if (example_get_balance(account2) /= 400.0d0) then
        print *, "unexpected balance on account2"
        stop 1
    end if
    call example_free(account2)

end program
