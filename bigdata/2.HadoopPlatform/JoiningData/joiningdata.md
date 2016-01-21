

### Part1
#### Test the program in serial execution using the following Unix utilities and piping commands:
    cat join1_File*.txt | ./join1_mapper.py | sort | ./join1_reducer.py


#### Run the Hadoop streaming command:
    hadoop jar /usr/lib/hadoop-mapreduce/hadoop-streaming.jar \
       -input /user/root/input \
       -output /user/root/output_join \   
       -mapper /home/cloudera/join1_mapper.py \   
       -reducer /home/cloudera/join1_reducer.py


### Part2: A new join problem
#### What is the total number of viewers for shows on ABC?
#### Test the program in serial execution using the following Unix utilities and piping commands:
    cat join2*.txt | ./join2_mapper.py | sort | ./join2_reducer.py

implement two mapper and reducer python code.
    hadoop jar /usr/lib/hadoop-mapreduce/hadoop-streaming.jar \
       -input /user/root/input_join2 \
       -output /user/root/output_join2 \
       -mapper /home/cloudera/join2_mapper.py \
       -reducer /home/cloudera/join2_reducer.py


