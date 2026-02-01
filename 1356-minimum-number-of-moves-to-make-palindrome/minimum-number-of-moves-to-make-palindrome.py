class Solution(object):
    def minMovesToMakePalindrome(self, s):
        def computeOperations(string, ch, l, r, from_back=True):
            index = -1

            if from_back:
                for i in range(r, l, -1):
                    if string[i] == ch:
                        index = i
                        break
            else:
                for i in range(l, r):
                    if string[i] == ch:
                        index = i
                        break

            if index == -1:
                return string, -1

            s = list(string)

            if from_back:
                # bubble RIGHT to r
                i = index
                while i < r:
                    s[i], s[i + 1] = s[i + 1], s[i]
                    i += 1
            else:
                # bubble LEFT to l
                i = index
                while i > l:
                    s[i], s[i - 1] = s[i - 1], s[i]
                    i -= 1

            return "".join(s), index

        """
        :type s: str
        :rtype: int
        """
        string = s
        l, r = 0, len(string) - 1
        minMoves = 0

        while l < r:
            if string[l] != string[r]:
                newString, index = computeOperations(string, string[l], l, r, True)
                if index != -1:
                    k = r - index
                    minMoves += k
                    string = newString
                else:
                    newString, index = computeOperations(string, string[r], l, r, False)
                    k = index - l
                    minMoves += k
                    string = newString

            l += 1
            r -= 1

        return minMoves
        