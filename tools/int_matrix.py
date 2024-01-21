import sys

def create_matrix_file(rows, cols):
    matrix = [[0] * cols for _ in range(rows)]

    filename = "matrix"

    with open(filename, 'w') as file:
        for row in matrix:
            file.write(' '.join(map(str, row)) + '\n')

    print(f"File '{filename}' created with a matrix of {rows} rows and {cols}")

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python script.py <number of rows> <number of columns>")
        sys.exit(1)

    try:
        rows = int(sys.argv[1])
        cols = int(sys.argv[2])
    except ValueError:
        print("Dimensions must be integers.")
        sys.exit(1)

    create_matrix_file(rows, cols)