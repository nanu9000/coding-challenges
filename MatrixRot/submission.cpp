#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

#include "CircularLinkedList.h"

std::vector<int> strsplit(std::string str, char delim) {
	std::vector<int> elems;
	std::stringstream ss(str);
	std::string item;
    while (getline(ss, item, delim)) {
        elems.push_back( stoi(item) );
    }
    return elems;
}

CircularLinkedList loop_roller(std::vector< std::vector<int> > rows, int num_rows, int num_cols, int loop_number) {
	int start_row = loop_number;
	int start_col = loop_number;
	int end_row = num_rows - loop_number - 1;
	int end_col = num_cols - loop_number - 1;

	CircularLinkedList cll = CircularLinkedList();

	/* Top row */
	for (int i = start_col; i < end_col; ++i) {
		cll.insert(rows[start_row][i]);
	}

	/* Right column */
	for (int i = start_row; i < end_row; ++i) {
		cll.insert(rows[i][end_col]);
	}

	/* Bottom row */
	for (int i = end_col; i > start_col; --i) {
		cll.insert(rows[end_row][i]);
	}

	/* Left column */
	for (int i = end_row; i > start_row; --i) {
		cll.insert(rows[i][start_col]);
	}

	return cll;
}

std::vector< std::vector<int> > loop_unroller(std::vector<CircularLinkedList> loops, int num_rows, int num_cols) {
	std::vector< std::vector<int> > matrix;
	for (int i = 0; i < num_rows; ++i) {
		std::vector<int> vec(num_cols);
		matrix.push_back(vec);
	}

	for (int loop_number = 0; loop_number < loops.size(); ++loop_number) {
		int start_row = loop_number;
		int start_col = loop_number;
		int end_row = num_rows - loop_number - 1;
		int end_col = num_cols - loop_number - 1;
		CircularLinkedList cll = loops[loop_number];

		/* Top row */
		for (int i = start_col; i < end_col; ++i) {
			matrix[start_row][i] = cll.head->val;
			cll.head = cll.head->next;
		}

		/* Right column */
		for (int i = start_row; i < end_row; ++i) {
			matrix[i][end_col] = cll.head->val;
			cll.head = cll.head->next;
		}

		/* Bottom row */
		for (int i = end_col; i > start_col; --i) {
			matrix[end_row][i] = cll.head->val;
			cll.head = cll.head->next;
		}

		/* Left column */
		for (int i = end_row; i > start_row; --i) {
			matrix[i][start_col] = cll.head->val;
			cll.head = cll.head->next;
		}
	}

	return matrix;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    std::string first_line;
    getline(std::cin, first_line);
    std::vector<int> first_line_vec = strsplit(first_line, ' ');
    int num_rows = first_line_vec[0];
    int num_cols = first_line_vec[1];
    int num_rots = first_line_vec[2];

    std::vector< std::vector<int> > rows;
    for (int i = 0; i < num_rows; ++i) {
    	std::string line;
    	getline(std::cin, line);
    	rows.push_back(strsplit(line, ' '));
    }

    std::vector<CircularLinkedList> loops;

    int num_loops = std::min(num_rows, num_cols) / 2;
    for (int i = 0; i < num_loops; ++i) {
    	CircularLinkedList loop = loop_roller(rows, num_rows, num_cols, i);
    	loop.rotate(num_rots);
    	loops.push_back(loop);
    }

    std::vector< std::vector<int> > matrix = loop_unroller(loops, num_rows, num_cols);

    for (int i = 0; i < num_rows; ++i) {
    	for (int j = 0; j < num_cols; ++j) {
    		std::cout << matrix[i][j];
    		if (j == num_cols - 1) {
    			std::cout << std::endl;
    		} else {
    			std::cout << " ";
    		}
    	}
    }

    return 0;
}