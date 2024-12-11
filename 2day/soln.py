import pdb

def soln(filename='input.txt'):
    count = 0
    with open(filename, 'r') as file:
        for line in file:
            x = line.split()
            prev = None
            incr = None
            # breakpoint()
            for i, cur in enumerate(x):
                cur = int(cur)
                if prev == None: 
                    if abs(cur - int(x[1])) > 3:
                        count -= 1
                        break
                    incr = True if cur < int(x[i+1]) else False
                    prev = cur
                    continue

                if prev < cur and not incr:
                    count -= 1
                    break
                elif prev > cur and incr:
                    count -= 1
                    break
                if abs(prev-cur) > 3 or prev-cur == 0:
                    count -= 1
                    break
                prev = cur

            count += 1
            
    return count
    
if __name__ == "__main__":
    print(soln())
