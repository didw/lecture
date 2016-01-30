## Assignment: Advanced Join in Spark

### Verify input data
hadoop fs -ls /user/cloudera/input_join2

### Read shows files

show_views_file = sc.textFile("/user/cloudera/input_join2/join2_gennum?.txt")
show_views_file.take(2)

### Parse shows files

def split_show_views(line):
    show, views = line.split(",")
    return (show, views)
show_views = show_views_file.map(split_show_views)

### Read channel files

show_channel_file = sc.textFile("/user/cloudera/input_join2/join2_genchan?.txt")

### Parse channel files

def split_show_channel(line):
    show, channel = line.split(",")
    return (show, channel)

show_channel = show_channel_file.map(split_show_channel)


### Join the 2 datasets

joined_dataset = show_views.join(show_channel)


### Extract channel as key

def extract_channel_views(show_views_channel): 
    channel = show_views_channel[1][1]
    views = int(show_views_channel[1][0])
    return (channel, views)

channel_views = joined_dataset.map(extract_channel_views)

### Sum across all channels

def some_function(a, b):
    return a + b

channel_views.reduceByKey(some_function).collect()

Out[57]: 
[(u'XYZ', 5208016),
 (u'DEF', 8032799),
 (u'CNO', 3941177),
 (u'BAT', 5099141),
 (u'NOX', 2583583),
 (u'CAB', 3940862),
 (u'BOB', 2591062),
 (u'ABC', 1115974),
 (u'MAN', 6566187)]


