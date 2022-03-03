def pascal_triangle(n):
    row=[1]
    z=[0]
    for i in range(n):
        print(row)
        row=[l+r for l,r in zip(row+z,z+row)]


pascal_triangle(5)

