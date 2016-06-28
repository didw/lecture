import sqlite3

def create_table():
    try:
        db = sqlite3.connect("test.db")
        cur = db.cursor()
        q = "create table student(name text, age int)"
        cur.execute(q)
        db.commit()
        db.close()
        print("database created")
    except Exception as err:
        print("error:", err)

def insert_data(name, age):
    try:
        db = sqlite3.connect("test.db")
        cur = db.cursor()
        #q = "insert into student(name, age) values('{}',{})".format(name, age)
        q = "insert into student(name, age) values(?,?)"
        cur.execute(q, (name, age))
        db.commit()
        db.close()
        print("Success to insert data into table")
    except Exception as err:
        print("error:", err)

def insert_many_data(data):
    try:
        db = sqlite3.connect("test.db")
        cur = db.cursor()
        #q = "insert into student(name, age) values('{}',{})".format(name, age)
        q = "insert into student(name, age) values(?,?)"
        cur.executemany(q, data)
        db.commit()
        db.close()
        print("Success to insert many data into table")
    except Exception as err:
        print("error:", err)

def update_data():
    try:
        db = sqlite3.connect("test.db")
        cur = db.cursor()
        q = "update student set age=111 where name='AAA'"
        cur.execute(q)
        db.commit()
        db.close()
        print("Success to update data in table")
    except Exception as err:
        print("error:", err)

def delete_data():
    try:
        db = sqlite3.connect("test.db")
        cur = db.cursor()
        q = "delete from student where age=2"
        cur.execute(q)
        db.commit()
        db.close()
        print("Success to delete data from table")
    except Exception as err:
        print("error:", err)

def select_data():
    try:
        db = sqlite3.connect("test.db")
        cur = db.cursor()
        q = "select * from student order by name"
        cur.execute(q)
        #data = cur.fetchall()
        #print(data)
        for n,a in cur:
            print(n,a)
        
        db.commit()
        db.close()
        print("Success to select data from table")
    except Exception as err:
        print("error:", err)

if __name__ == '__main__':
    select_data()

