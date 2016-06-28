import sqlite3

def create_table():
    try:
        db = sqlite3.connect("library.db")
        cur = db.cursor()
        q = "create table library(reg text, date text, name text, pub text, author text, kind text, etc1 text, etc2 text, etc3 text)"
        cur.execute(q)
        db.commit()
        db.close()
    except Exception as err:
        print("error:", err)

def insert_data(reg, date, name, pub, author, kind, etc1, etc2, etc3):
    try:
        db = sqlite3.connect("library.db")
        cur = db.cursor()
        q = "insert into library(reg, date, name, pub, author, kind, etc1, etc2, etc3) values(?,?,?,?,?,?,?,?,?)"
        print(q)
        cur.execute(q, (reg, date, name, pub, author, kind, etc1, etc2, etc3))
        db.commit()
        db.close()
    except Exception as err:
        print("error:", err)

def insert_many_data(data):
    try:
        db = sqlite3.connect("library.db")
        cur = db.cursor()
        q = "insert into library(reg, date, name, pub, author, kind, etc1, etc2, etc3) values(?,?,?,?,?,?,?,?,?)"
        print(q)
        cur.executemany(q, data)
        db.commit()
        db.close()
    except Exception as err:
        print("error:", err)

def update_data(reg, date, name, pub, author, kind, etc1, etc2, etc3):
    try:
        db = sqlite3.connect("library.db")
        cur = db.cursor()
        q = "update library set date='{}', name='{}', pub='{}', author='{}', kind='{}', etc1='{}', etc2='{}', etc3='{}' where reg='{}'".format(date, name, pub, author, kind, etc1, etc2, etc3, reg)
        print(q)
        cur.execute(q)
        db.commit()
        db.close()
        print("{}의 정보가 업데이트되었습니다.".format(name))
    except Exception as err:
        print("error:", err)

def delete_data(reg):
    try:
        db = sqlite3.connect("library.db")
        cur = db.cursor()
        q = "delete from library where reg='{}'".format(reg)
        print(q)
        cur.execute(q)
        db.commit()
        db.close()
        print("{} 데이터가 삭제되었습니다.".format(reg))
    except Exception as err:
        print("error:", err)

def select_data():
    try:
        db = sqlite3.connect("library.db")
        cur = db.cursor()
        q = "select * from library"
        print(q)
        cur.execute(q)
        data = cur.fetchall()
        db.commit()
        db.close()
        return data
    except Exception as err:
        print("error:", err)

def search_data_by(name, pub, author):
    try:
        db = sqlite3.connect("library.db")
        cur = db.cursor()
        q = "select * from library where name='{}' and pub='{}' and author='{}'".format(name, pub, author)
        print(q)
        cur.execute(q)
        data = cur.fetchall()
        db.commit()
        db.close()
        return data
    except Exception as err:
        print("error:", err)

def search_data_by_reg(name):
    try:
        db = sqlite3.connect("library.db")
        cur = db.cursor()
        q = "select * from library where reg='{}'".format(name)
        print(q)
        cur.execute(q)
        data = cur.fetchall()
        db.commit()
        db.close()
        return data
    except Exception as err:
        print("error:", err)

def search_data_by_name(name):
    try:
        db = sqlite3.connect("library.db")
        cur = db.cursor()
        q = "select * from library where name='{}'".format(name)
        print(q)
        cur.execute(q)
        data = cur.fetchall()
        db.commit()
        db.close()
        return data
    except Exception as err:
        print("error:", err)

def search_data_by_pub(name):
    try:
        db = sqlite3.connect("library.db")
        cur = db.cursor()
        q = "select * from library where pub='{}'".format(name)
        print(q)
        cur.execute(q)
        data = cur.fetchall()
        db.commit()
        db.close()
        return data
    except Exception as err:
        print("error:", err)

def search_data_by_author(name):
    try:
        db = sqlite3.connect("library.db")
        cur = db.cursor()
        q = "select * from library where author='{}'".format(name)
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
        db = sqlite3.connect("library.db")
        cur = db.cursor()
        q = "select * from library order by {}".format(menu)
        print(q)
        cur.execute(q)
        data = cur.fetchall()
        db.commit()
        db.close()
        return data
    except Exception as err:
        print("error:", err)

def data_input_manual():
    data = [('A-001', '2009-10-19', '엑셀2007',      '한솔출판사', '김길동', '컴퓨터', '1', '2', '3'),
            ('A-002', '2010-11-19', '파워포인트2007', '한솔출판사', '김강산', '컴퓨터', '1', '2', '3'),
            ('A-003', '2011-06-19', '엑셀2010',      '한솔출판사', '이순신', '컴퓨터', '1', '2', '3'),
            ('A-004', '2012-10-30', '파이썬',        '한글출판사', '한하늘', '소설', '1', '2', '3')]
    insert_many_data(data)
    print("데이터가 잘 입력되었습니다.")

def data_input():
    cont = 'y'
    while cont == 'y':
        reg = input("관리번호:")
        date = input("등록일:")
        name = input("제목:")
        pub = input("출판사:")
        author= input("저자:")
        kind = input("종류:")
        etc1 = input("etc1:")
        etc2 = input("etc2:")
        etc3 = input("etc3:")
        insert_data(reg, date, name, pub, author, kind, etc1, etc2, etc3)
        cont = input('계속 입력하시겠습니까?(y/n)')
    print("데이터가 잘 입력되었습니다.")

def data_print(menu):
    if menu == '':
        data = select_data()
    else:
        data = print_data_order_by(menu)
    print_data(data)

def print_data(data):
    print("======================================================")
    print("reg, date, name, pub, author, kind, etc1, etc2, etc3")
    print("======================================================")
    for r, d, n, p, a, k, e1, e2, e3 in data:
        print("  {}   {}    {}    {}     {}     {}     {}     {}     {}   ".format(r, d, n, p, a, k, e1, e2, e3))
    print("=======================================================")


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
    data = search_data_by_name(name)
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
        if   menu == 1: data_input_manual()
        elif menu == 1: data_input()
        elif menu == 2: data_print('')
        elif menu == 3: data_delete()
        elif menu == 4: data_update()
        elif menu == 5: data_search()
        elif menu == 6: data_sort()
        menu = -1
    print("프로그램을 종료합니다.")

if __name__ == '__main__':
    main_process()

