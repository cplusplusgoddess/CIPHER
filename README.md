# CIPHER
for Eric @Google (Interview challenge)
PROBLEM:

ROT(n, s) is defined as the rotation by n characters of string:
  ROT(“abc”) = “bcd”
  ROT(“zabc”) = “abcd”
  ROT(“rot”) = “tqv”
Etc.
We define two strings a, b, to be equivalent if there exists m such that applying rot(n) m times on a gives b.
For example:
  “abc”, “bcd”, “def”, “zab” are all equivalent in rot(1).
  “abc”, “cde”, “efg” are all equivalent in rot(2).

Given n, and a list of strings, provide the list of all equivalent strings.
For example, for n = 1
  “abc”, “cde”, “aaa”, “ddd”, “efg” has two sets of strings:
      “abc”, “cde”, “efg”
      “aaa” , “ddd”
