### Create some data:
    echo "A long time ago in a galaxy far far away" > /home/cloudera/testfile1
    echo "Another episode of Star Wars" > /home/cloudera/testfile2

### Create a directory on the HDFS file system
    hadoop fs -mkdir /user/root/input

### Copy the files from local filesystem to the HDFS filesystem:
    hadoop fs -put /home/cloudera/testfile1 /user/cloudera/input
    hadoop fs -put /home/cloudera/testfile2 /user/cloudera/input

### Run the Hadoop WordCount example with the input and output specified.
    hadoop jar /usr/lib/hadoop-mapreduce/hadoop-streaming.jar \
      -input /user/root/input \
      -output /user/root/output_new \
      -mapper /home/cloudera/wordcount_mapper.py \
      -reducer /home/cloudera/wordcount_reducer.py

### Check the output file to see the results:
    hadoop fs -cat /user/cloudera/output_new/part-00000

### View the output directory:
    hadoop fs -cat /user/cloudera/output_new/part-00000

### Streaming options:
    hadoop jar /usr/lib/hadoop-mapreduce/hadoop-streaming.jar --help

    hadoop jar /usr/lib/hadoop-mapreduce/hadoop-streaming.jar \
       -input /user/root/input \
       -output /user/root/output_new_0 \
       -mapper /home/cloudera/wordcount_mapper.py \
       -reducer /home/cloudera/wordcount_reducer.py \
       -numReduceTasks 0

    hadoop fs -getmerge /user/cloudera/output_new_0/* wordcount_num0_output.txt

### Change the number of reducers to 2 and answer the related quiz question at the end of the video lesson
    hadoop jar /usr/lib/hadoop-mapreduce/hadoop-streaming.jar \
       -input /user/root/input \
       -output /user/root/output_new_2 \
       -mapper /home/cloudera/wordcount_mapper.py \
       -reducer /home/cloudera/wordcount_reducer.py \
       -numReduceTasks 2

    hadoop fs -getmerge /user/root/output_new_2/* wordcount_num2_output.txt


