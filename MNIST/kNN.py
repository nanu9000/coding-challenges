import csv
from collections import Counter
# import math for sqrt
import numpy as np
# import pyspark for distance calculations later

#WARNING: This script is VERY SLOW!

# Dimensions of a and b expected to be 1xN
# Euclidean Distance function: 
# d = sum (a[i] - b[i])^2
def dist(train_data, test_data):
	return sum((train_data - test_data) ** 2)

k = 3

testfile = open('test.csv', 'rb')
trainfile = open('train.csv', 'rb')

train_data = csv.reader(trainfile)
test_data = csv.reader(testfile)

train_data.next()
test_data.next()

train = []
test = []
for row in train_data:
	new_row = []
	for val in row:
		new_row.append(int(val))
	train.append(np.array(new_row))


sumbissionfile = open('submission.csv', 'w')
sumbissionfile.write("ImageId,Label\n")
test_number = 1
for row in test_data:
	tp = []
	for val in row:
		tp.append(int(val))
	test_point = np.array(tp)

	distances = []
	for train_point in train:
		label = train_point[0]
		d = dist(train_point[1:], test_point)
		distances.append( [d, train_point[0]] )
	sorted_distances = np.argsort(distances, axis=0)

	labels = []
	for i in xrange(k):
		label = distances[sorted_distances[i][0]][1]
		labels.append(label)

	sumbissionfile.write(str(test_number))
	sumbissionfile.write(",")
	sumbissionfile.write(str(Counter(labels).most_common(1)[0][0]))
	sumbissionfile.write("\n")
	test_number = test_number + 1
