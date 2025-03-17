==454497== Memcheck, a memory error detector
==454497== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==454497== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==454497== Command: ./push_swap 3 1  3
==454497== 
==454497== 
==454497== FILE DESCRIPTORS: 3 open (3 std) at exit.
==454497== 
==454497== HEAP SUMMARY:
==454497==     in use at exit: 8 bytes in 1 blocks
==454497==   total heap usage: 12 allocs, 11 frees, 124 bytes allocated
==454497== 
==454497== 8 bytes in 1 blocks are still reachable in loss record 1 of 1
==454497==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==454497==    by 0x4018BE: ft_calloc (in /home/ihajji/Desktop/42/push_swap/push_swap)
==454497==    by 0x4019B4: ft_split (in /home/ihajji/Desktop/42/push_swap/push_swap)
==454497==    by 0x4013D2: parse_args (main.c:82)
==454497==    by 0x401593: main (main.c:115)
==454497== 
==454497== LEAK SUMMARY:
==454497==    definitely lost: 0 bytes in 0 blocks
==454497==    indirectly lost: 0 bytes in 0 blocks
==454497==      possibly lost: 0 bytes in 0 blocks
==454497==    still reachable: 8 bytes in 1 blocks
==454497==         suppressed: 0 bytes in 0 blocks
==454497== 
==454497== For lists of detected and suppressed errors, rerun with: -s
==454497== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
