class Solution:
    def createGrid(self, m: int, n: int) -> list[str]:
        ans = []
        marker = [0, 0]
        for i in range(m):
            s = ""
            for j in range(n):
                print(i, j)
                if i == j:
                    s += "."
                    marker[0] = i
                    marker[1] = j
                    if j != n - 1:
                        s += "."
                        marker[1] = j + 1
                    break
                else:
                    s += "#"
            k = len(s)
            while k < n:
                s += "#"
                k += 1
            ans.append(s)
        
        if marker[0] < m - 1:
            i = marker[0]
            while i < m:
                row = list(ans[i])
                row[n-1] = "."
                ans[i] = "".join(row)
                i += 1
        if marker[1] < n - 1:
            i = marker[1]
            row = list(ans[m - 1])
            while i < n:
                row[i] = "."
                i += 1
            ans[m - 1] = "".join(row)
        return ans
        
            
            
