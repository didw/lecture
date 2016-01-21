

### Part1
#### Test the program in serial execution using the following Unix utilities and piping commands:
    cat join1_File*.txt | ./join1_mapper.py | sort | ./join1_reducer.py


#### Run the Hadoop streaming command:
    hadoop jar /usr/lib/hadoop-mapreduce/hadoop-streaming.jar \
       -input /user/root/input \
       -output /user/root/output_join \   
       -mapper /home/cloudera/join1_mapper.py \   
       -reducer /home/cloudera/join1_reducer.py
