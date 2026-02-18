class Solution:
    def fibo( self, n : int ) -> int: 
        if( n == 0 ):
            return 0
        if ( n == 1):
            return 1
        return self.fibo(n-1) + self.fibo(n-2)
