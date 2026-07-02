class Solution:
    def minTime(self, s: str, order: List[int], k: int) -> int:
        n = len(s)
        total = n * (n + 1) // 2

        if total < k:
            return -1

        def check(t):
            star = [False] * n
            for i in range(t + 1):
                star[order[i]] = True

            invalid = 0
            length = 0

            for i in range(n):
                if not star[i]:
                    length += 1
                else:
                    invalid += length * (length + 1) // 2
                    length = 0

            invalid += length * (length + 1) // 2

            return total - invalid >= k

        left, right = 0, n - 1
        ans = -1

        while left <= right:
            mid = (left + right) // 2
            if check(mid):
                ans = mid
                right = mid - 1
            else:
                left = mid + 1

        return ans
        