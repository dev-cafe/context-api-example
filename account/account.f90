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
