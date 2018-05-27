#!/usr/bin/env bash
# make re

function intro()
{
    echo; echo;
    echo ========================================
    echo "test de push_swap avec $1 numero 10 fois"
}

function border()
{
    a=`./checker $1  << EOF
EOF`
b=`./push_swap $1`

if [ "$a" != "OK" ];
	then
		echo "-------   $1"
		echo "check err : $a"
	fi

    if [ "$b" != "" ];
    then
		echo "-------   $1"
		echo "push err : $b"
	fi
}

function err_str ()
{
    echo ========================================
    echo "test avec $1 en str"

    a=`./checker $1`
    b=`./push_swap $1`

	if [ "$a" != "Error" ];
	then
		echo "-------   $1"
		echo "check err : $a"
	fi

    if [ "$b" != "Error" ];
    then
		echo "-------   $1"
		echo "push err : $b"
	fi

    valgrind --log-fd=1 ./checker $1 | grep "definitely lost"
    valgrind --log-fd=1 ./push_swap $1 | grep "definitely lost"
}

function err_arg ()
{
    echo ========================================
    echo "test avec $1 en arg"

    a=`./checker $@`
    b=`./push_swap $@`

	if [ "$a" != "Error" ];
	then
		echo "-------   $@"
		echo "check err : $a"
	fi

    if [ "$b" != "Error" ];
    then
		echo "-------   $@"
		echo "push err : $b"
	fi

    valgrind --log-fd=1 ./checker $@ | grep "definitely lost"
    valgrind --log-fd=1 ./push_swap $@ | grep "definitely lost"
}

#    # que push push
#    nb="puts (1..10).to_a.shuffle.join(' ')"
#    ARG=`ruby -e "$nb"` ;
#    valgrind --log-fd=1 ./push_swap "$ARG"
#
#    # que check check
#    nb="puts (1..10).to_a.shuffle.join(' ')"
#    ARG=`ruby -e "$nb"` ;
#    ./push_swap "$ARG"  | valgrind --log-fd=1 ./checker "$ARG"


function memcheck()
{
    nb="puts (1..$1).to_a.shuffle.join(' ')"
    ARG=`ruby -e "$nb"` ;
    valgrind --log-fd=1 ./push_swap "$ARG" | grep "definitely lost"
    ./push_swap "$ARG"  | valgrind --log-fd=1 ./checker "$ARG" | grep "definitely lost"
    ./push_swap "$ARG"  | ./checker "$ARG"
    ./push_swap "$ARG"  | wc -l

}

function check_mem()
{
    echo; echo;
    echo ========================================
    echo "test de push_swap avec $1 numero 10 fois"

    for tt in `seq 1 10`
    do
       memcheck $1
       echo;
    done
}



#*------------------------------------*\
#    simple error
*------------------------------------*/
echo "bullshit test -------------------------------"
err_str a
err_str "a"

err_str a d
err_str "a b"

err_arg 444d
err_str "444d"

err_arg 444d
err_str "444d 55"

err_arg a111
err_str "a111 887"

err_arg -111-
err_str "-111-"

err_str "55 44 22 44"
err_arg 55 44 22 44

err_str "14 4 44 4564654646465"
err_arg 14 4 44 4564654646465


#*------------------------------------*\
#    LIMIT
#*------------------------------------*/
border 2147483647
border "2147483647"
border -2147483648
border "-2147483648"
border 0
border "0"
border -0
border "-0"
valgrind --log-fd=1 ./checker 0 | grep "definitely lost"
valgrind --log-fd=1 ./push_swap 0 | grep "definitely lost"

valgrind --log-fd=1 ./checker  | grep "definitely lost"
valgrind --log-fd=1 ./push_swap | grep "definitely lost"



check_mem 1
check_mem 2
check_mem 3
check_mem 15
check_mem 50
check_mem 100
check_mem 500
check_mem 1000
check_mem 5000

#leaks_check



#echo "$b"

# while true; do; ARG=`ruby -e "puts (-100..10000).to_a.shuffle.join(' ')"` | ./push_swap $ARG | ./checker $ARG ; done
# while 1; do; leaks_push checker | grep "Process" | grep "leaks_push"; done


