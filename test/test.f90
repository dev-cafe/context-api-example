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
