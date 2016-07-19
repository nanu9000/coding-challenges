import csv

testfile = open('test.csv', 'rb')
trainfile = open('train.csv', 'rb')
train_data = csv.reader(trainfile)
for row in train_data:
    print row