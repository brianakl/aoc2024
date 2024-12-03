import numpy as np

def soln(filename='input.txt'):
    r1, r2 = [], []
    with open(filename, 'r') as file:
        for line in file:
            x = line.split()
            r1.append(int(x[0]))
            r2.append(int(x[1]))

    r1.sort()
    r2.sort()

    sum = 0

    for i in range(len(r1)):
        sum += np.abs(r1[i] - r2[i])

    return sum
    
if __name__ == "__main__":
    print(soln())
