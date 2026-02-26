class Solution:
    def numSteps(self, s: str) -> int:
        num = 0
        idx = int(2**(len(s) - 1))

        for c in s:
            num += int(c) * idx
            idx //= 2
        print(num)
        steps = 0
        while(num != 1):
            if(num%2):
                num += 1
            else:
                num //= 2
            steps += 1
        return steps
    

        