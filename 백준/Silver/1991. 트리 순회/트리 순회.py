

n = int(input())

left = [-1] * 26
right = [-1] * 26

for _ in range(n):
    a, b, c = map(str, input().split())
    idx = ord(a) - ord('A')
    if b != '.':
        left[idx] = ord(b) - ord('A')
    if c != '.':
        right[idx] = ord(c) - ord('A')


def preorder(u, arr):
    if u == -1:
        return
    arr.append(chr(u + ord('A')))
    preorder(left[u], arr)
    preorder(right[u], arr)

def inorder(u, arr):
    if u == -1:
        return
    inorder(left[u], arr)
    arr.append(chr(u + ord('A')))
    inorder(right[u], arr)

def postorder(u, arr):
    if u == -1:
        return
    postorder(left[u], arr)
    postorder(right[u], arr)
    arr.append(chr(u + ord('A')))

root = 0
pre, ino, post = [], [], []

preorder(root, pre)
inorder(root, ino)
postorder(root, post)

print(''.join(pre))
print(''.join(ino))
print(''.join(post))