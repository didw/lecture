import mysql.connector as mc

def insert_data(name, age, birth):
    try:
        config={'user':'root', 'password':'1234', 'host':'127.0.0.1', 
                'database':'world'}
        db = mc.connect( **config )
        cur = db.cursor()
        
        #q = "insert into student(name, age, birth) values('Juno', 10, '1989-01-25')"
        q = "insert into student(name, age, birth) values(%s, %s, %s)"
        
        cur.execute(q, (name, age, birth))
        db.commit()
        db.close()
        print("Success to insert data")
    except Exception as err:
        print("error:", err)

def insert_many_data(data):
    try:
        config={'user':'root', 'password':'1234', 'host':'127.0.0.1', 
                'database':'world'}
        db = mc.connect( **config )
        cur = db.cursor()
        
        #q = "insert into student(name, age, birth) values('Juno', 10, '1989-01-25')"
        q = "insert into student(name, age, birth) values(%s, %s, %s)"
        
        cur.executemany(q, data)
        db.commit()
        db.close()
        print("Success to insert many data")
    except Exception as err:
        print("error:", err)

def update_data(name='', age=0, birth=''):
    try:
        config={'user':'root', 'password':'1234', 'host':'127.0.0.1', 
                'database':'world'}
        db = mc.connect( **config )
        cur = db.cursor()
        
        q = "update student set birth='1972-01-01' where name='James'"
        
        cur.execute(q)
        db.commit()
        db.close()
        print("Success to update data")
    except Exception as err:
        print("error:", err)

def delete_data(name='', age=0, birth=''):
    try:
        config={'user':'root', 'password':'1234', 'host':'127.0.0.1', 
                'database':'world'}
        db = mc.connect( **config )
        cur = db.cursor()
        data = ('James',)              
        q = "delete from student where name=%s"        
        cur.execute(q, data)
        db.commit()
        db.close()
        print("Success to delete data")
    except Exception as err:
        print("error:", err)

def print_data():
    try:
        config = {'user':'root', 'password':'1234', 'host':'127.0.0.1',
                  'database':'world'}
        db = mc.connect( ** config )
        cur = db.cursor()
        q = "select * from student"
        cur.execute(q)
        #data = cur.fetchall()
        #print(data)
        #print(data[0][2].year)
        for n,a,b in cur:
            print("{}, {}, {}".format(n,a,"{}/{}/{}".format(b.month,b.day,b.year)))
        db.close()
        print("Success to print all data")
    except Exception as err:
        print("error:", err)

if __name__ == '__main__':
    #insert_data('James', 29, '1892-02-01')
    #insert_many_data([('Kim', 3, '2010-02-01'),('Evan', 19, '2002-02-01'),])
    #delete_data()
    print_data()
