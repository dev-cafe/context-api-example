module account

    use, intrinsic :: iso_c_binding, only: c_ptr, c_double

    implicit none

    public account_new
    public account_free
    public account_deposit
    public account_withdraw
    public account_get_balance

    private

    interface account_new
        function account_new() result(context) bind (c)
            import :: c_ptr
            type(c_ptr) :: context
        end function
    end interface

    interface account_free
        subroutine account_free(context) bind (c)
            import :: c_ptr
            type(c_ptr), value :: context
        end subroutine
    end interface

    interface account_deposit
        subroutine account_deposit(context, f) bind (c)
            import :: c_ptr, c_double
            type(c_ptr), value :: context
            real(c_double), value, intent(in) :: f
        end subroutine
    end interface

    interface account_withdraw
        subroutine account_withdraw(context, f) bind (c)
            import :: c_ptr, c_double
            type(c_ptr), value :: context
            real(c_double), value, intent(in) :: f
        end subroutine
    end interface

    interface account_get_balance
        function account_get_balance(context) result(r) bind (c)
            import :: c_ptr, c_double
            type(c_ptr), value, intent(in) :: context
            real(c_double) :: r
        end function
    end interface

end module


program test

    use account, only: account_new, &
                       account_free, &
                       account_deposit, &
                       account_withdraw, &
                       account_get_balance

    use, intrinsic :: iso_c_binding, only: c_ptr

    implicit none

    type(c_ptr) :: account1
    type(c_ptr) :: account2

    account1 = account_new()

    call account_deposit(account1, 100.0d0)
    call account_deposit(account1, 100.0d0)

    account2 = account_new()

    call account_deposit(account2, 200.0d0)
    call account_deposit(account2, 200.0d0)

    call account_withdraw(account1, 50.0d0)

    if (account_get_balance(account1) /= 150.0d0) then
        print *, "unexpected balance on account1"
        stop 1
    end if
    call account_free(account1)

    if (account_get_balance(account2) /= 400.0d0) then
        print *, "unexpected balance on account2"
        stop 1
    end if
    call account_free(account2)

end program
