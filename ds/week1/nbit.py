# global A
# A = 'bbb'
#
# def binary(n):
#     if (n < 1):
#         print (A)
#     else :
#         # TypeError: 'str' object does not support item assignment
#         # A[n - 1] = 0
#         binary(n - 1)
#         A[n - 1] = 1
#         binary(n - 1)

def binary(str, n):
    if (n < 1):
        print (str)
    else:
        # binary('0' + str, n - 1)
        # binary('1' + str, n - 1)
        binary(str + '0', n - 1)
        binary(str + '1', n - 1)


binary('', 3)