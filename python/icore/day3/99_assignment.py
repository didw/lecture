import sqlite3

def create_table():
    try:
        db = sqlite3.connect("grade.db")
        cur = db.cursor()
        q = "create table grade(name text, kor int, eng int, math int)"
        cur.execute(q)
        db.commit()
        db.close()
    except Exception as err:
        print("error:", err)

def insert_data(name, kor, eng, math):
    try:
        db = sqlite3.connect("grade.db")
        cur = db.cursor()
        q = "insert into grade(name, kor, eng, math) values(?,?,?,?)"
        print(q)
        cur.execute(q, (name, kor, eng, math))
        db.commit()
        db.close()
    except Exception as err:
        print("error:", err)

def insert_many_data(data):
    try:
        db = sqlite3.connect("grade.db")
        cur = db.cursor()
        q = "insert into grade(name, kor, eng, math) values(?,?,?,?)"
        print(q)
        cur.executemany(q, data)
        db.commit()
        db.close()
    except Exception as err:
        print("error:", err)

def update_data(name, kor, eng, math):
    try:
        db = sqlite3.connect("grade.db")
        cur = db.cursor()
        q = "update grade set kor={}, eng={}, math={} where name='{}'".format(kor, eng, math, name)
        print(q)
        cur.execute(q)
        db.commit()
        db.close()
        print("{}의 정보가 업데이트되었습니다.".format(name))
    except Exception as err:
        print("error:", err)

def delete_data(name):
    try:
        db = sqlite3.connect("grade.db")
        cur = db.cursor()
        q = "delete from grade where name='{}'".format(name)
        print(q)
        cur.execute(q)
        db.commit()
        db.close()
        print("{} 데이터가 삭제되었습니다.".format(name))
    except Exception as err:
        print("error:", err)

def select_data():
    try:
        db = sqlite3.connect("grade.db")
        cur = db.cursor()
        q = "select * from grade"
        print(q)
        cur.execute(q)
        data = cur.fetchall()
        db.commit()
        db.close()
        return data
    except Exception as err:
        print("error:", err)

def search_data_by(name):
    try:
        db = sqlite3.connect("grade.db")
        cur = db.cursor()
        q = "select * from grade where name='{}'".format(name)
        print(q)
        cur.execute(q)
        data = cur.fetchall()
        db.commit()
        db.close()
        return data
    except Exception as err:
        print("error:", err)

def print_data_order_by(menu):
    try:
        db = sqlite3.connect("grade.db")
        cur = db.cursor()
        q = "select * from grade order by {}".format(menu)
        print(q)
        cur.execute(q)
        data = cur.fetchall()
        db.commit()
        db.close()
        return data
    except Exception as err:
        print("error:", err)

def data_input_manual():
    data = [('홍길동',10,20,30),('이순신',20,30,40),('박그네',30,40,50),('이명박',40,50,60)] 
    insert_many_data(data)
    print("데이터가 잘 입력되었습니다.")

def data_input():
    cont = 'y'
    while cont == 'y':
        name = input("이름:")
        kor  = int(input("국어:"))
        eng  = int(input("영어:"))
        math = int(input("수학:"))
        insert_data(name, kor, eng, math)
        cont = input('계속 입력하시겠습니까?(y/n)')
    print("데이터가 잘 입력되었습니다.")

def data_print(menu):
    if menu == '':
        data = select_data()
    else:
        data = print_data_order_by(menu)
    print_data(data)

def print_data(data):
    t, ak, ae, am, asum, aa = 0, 0, 0, 0, 0, 0
    print("======================================================")
    print("이름        국어      영어     수학    총점     평균")
    print("======================================================")
    for n,k,e,m in data:
        s = k+e+m
        a = s / 3
        ak += k
        ae += e
        am += m
        asum += s
        aa += a
        t += 1
        print("  {}        {}      {}     {}      {:3}     {:.1f}".format(n,k,e,m,s,a))
    print("=======================================================")
    if t > 1:
        print("           {:.1f}    {:.1f}   {:.1f}    {:3.1f}     {:.1f}".format(ak/t, ae/t, am/t, asum/t, aa/t))


def data_delete():
    name = input("삭제할 이름을 입력하세요:")
    delete_data(name)

def data_update():
    name = input("수정할 이름을 입력하세요:")
    kor  = int(input("국어:"))
    eng  = int(input("영어:"))
    math = int(input("수학:"))
    update_data(name, kor, eng, math)

def data_search():
    name = input("검색할 이름을 입력하세요:")
    data = search_data_by(name)
    print_data(data)

def data_sort():
    menu = 0
    menu_char = ['', 'name', 'kor', 'eng', 'math']
    while menu < 1 or 4 < menu:
        menu = int(input("무엇을 기준으로 정렬하겠습니까?(1: 이름, 2: 국어, 3: 영어, 4: 수학)"))
    data_print(menu_char[menu])

def input_menu():
    menu = input("""

======================
성적데이터 처리
======================
1. 입력
2. 보기
3. 삭제
4. 수정
5. 검색
6. 정렬
7. 종료

메뉴를 선택하세요:""")
    return menu

def main_process():
    create_table()
    while True:
        menu = int(input_menu())
        print(menu)
        if menu == 7:
            break;
        if menu < 1 or menu > 6:
            continue
        if   menu == 1: data_input()
        elif menu == 1: data_input_manual()
        elif menu == 2: data_print('')
        elif menu == 3: data_delete()
        elif menu == 4: data_update()
        elif menu == 5: data_search()
        elif menu == 6: data_sort()
        menu = -1
    print("프로그램을 종료합니다.")

if __name__ == '__main__':
    main_process()

