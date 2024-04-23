import struct
import random
random.seed(0)

R_size = 112
S_size = 224

R = []
S = []
for i in range(R_size):
    A = random.randint(1, 40)
    B = random.randint(1, 1000)
    R.append([A, B])

for i in range(S_size):
    C = random.randint(20, 60)
    D = random.randint(1, 1000)
    S.append([C, D])

blk_tuplenum = 7

for i in range(R_size // 7):
    with open(f'./data/{i}.blk', 'wb') as f:
        for j in range(blk_tuplenum):
            f.write(struct.pack('i', R[i*blk_tuplenum+j][0]))
            f.write(struct.pack('i', R[i*blk_tuplenum+j][1]))
        f.write(struct.pack('i', 0))
        f.write(struct.pack('i', i+1))

for i in range(S_size // 7):
    with open(f'./data/{R_size // 7 + i}.blk', 'wb') as f:
        for j in range(blk_tuplenum):
            f.write(struct.pack('i', S[i*blk_tuplenum+j][0]))
            f.write(struct.pack('i', S[i*blk_tuplenum+j][1]))
        f.write(struct.pack('i', 0))
        if (i == S_size // 7 - 1):
            f.write(struct.pack('i', 0))
        else:
            f.write(struct.pack('i', R_size // 7 + i+1))
