## Copy in MapReduce Code

#### 1. Open a Terminal (Right-click on Desktop or click Terminal icon in the top toolbar). Follow the steps below, copying and pasting or typing the code below to execute a simple word count example.

#### 2. Change Directory to the Hadoop library directory (type):

    cd /usr/local/hadoop

#### 3. Execute the Hadoop jar command to run the WordCount example (type):

    bin/hadoop jar share/hadoop/mapreduce/hadoop-mapreduce-examples-2.6.0.jar wordcount

#### 4. The wordcount example will output the warning that it needs input and output parameters (you should see this):

    Usage: wordcount <in> <out>

#### 5. Let's create a couple of text files with a few words in it for testing, or use a log file (type both commands, one at a time):

    echo "Hello world in HDFS" > /root/testfile1

    echo "Hadoop word count example in HDFS" > /root/testfile2

#### 6. Create directory for the input files on the HDFS file system (type):

    bin/hadoop fs -mkdir /user/root/input

#### 7. Copy the files from local filesystem to the HDFS filesystem (type both commands, one at a time):

    bin/hadoop fs -put /root/testfile1 /user/root/input

    bin/hadoop fs -put /root/testfile2 /user/root/input


## Run the Program

#### 8. Run the Hadoop WordCount example with the input and output specified (type):

    bin/hadoop jar share/hadoop/mapreduce/hadoop-mapreduce-examples-2.6.0.jar wordcount /user/root/input /user/root/output

#### 9. Hadoop prints out a large amount of logging information. After completion view the output directory (type):

    bin/hadoop fs -ls /user/root/output

#### 10. Check the output file to see the results (type):

    bin/hadoop fs -cat /user/root/output/part-r-00000

#### 11. Put the output in a location, in this case your cloudera user's home directory, where you can upload it for your submission (type):

    bin/hadoop fs -get /user/root/output/part-r-00000 /root/wordcount.txt
