from itertools import combinations

n = int(input())
num_list = [tuple(map(int, input().split())) for _ in range(n)]
num_set = set(num_list)
area = []

def calc_other_coordinates(a, b):
    c = ( a[1] - b[1] + b[0],  b[0] - a[0] + b[1])
    d = ( a[0] - b[1] + a[1],  a[1] - b[0] + a[0])
    return [c, d]

def main():
    for a, b in combinations(num_list, 2):
        list = calc_other_coordinates(a, b)
        print(list)
        
        if (list[0] in num_set and list[1] in num_set):
            area.append(pow(b[0]-a[0], 2)+pow(b[1]-a[1], 2))
    
    print(num_set)
    print(area)

if __name__ == "__main__":
    main()