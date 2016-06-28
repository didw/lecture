import mysql.connector as mc
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

def create_table():
    try:
        config={'user':'root', 'password':'1234', 'host':'127.0.0.1', 
                'database':'world'}
        db = mc.connect( **config )
        cur = db.cursor()
        q = "create table grade(name text, kor int, eng int, math int)"
        cur.execute(q)
        db.commit()
        db.close()
    except Exception as err:
        print("error:", err)

def insert_data(name, kor, eng, math):
    try:
        config={'user':'root', 'password':'1234', 'host':'127.0.0.1', 
                'database':'world'}
        db = mc.connect( **config )
        cur = db.cursor()
        q = "insert into grade(name, kor, eng, math) values(%s,%s,%s,%s)"
        print(q)
        cur.execute(q, (name, kor, eng, math))
        db.commit()
        db.close()
    except Exception as err:
        print("error:", err)

def insert_many_data(data):
    try:
        config={'user':'root', 'password':'1234', 'host':'127.0.0.1', 
                'database':'world'}
        db = mc.connect( **config )
        cur = db.cursor()
        q = "insert into grade(name, kor, eng, math) values(%s,%s,%s,%s)"
        print(q)
        cur.executemany(q, data)
        db.commit()
        db.close()
    except Exception as err:
        print("error:", err)

def update_data(name, kor, eng, math):
    try:
        config={'user':'root', 'password':'1234', 'host':'127.0.0.1', 
                'database':'world'}
        db = mc.connect( **config )
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
        config={'user':'root', 'password':'1234', 'host':'127.0.0.1', 
                'database':'world'}
        db = mc.connect( **config )
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
        config={'user':'root', 'password':'1234', 'host':'127.0.0.1', 
                'database':'world'}
        db = mc.connect( **config )
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
        config={'user':'root', 'password':'1234', 'host':'127.0.0.1', 
                'database':'world'}
        db = mc.connect( **config )
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
        config={'user':'root', 'password':'1234', 'host':'127.0.0.1', 
                'database':'world'}
        db = mc.connect( **config )
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
    print("   이름        국어      영어     수학    총점     평균")
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

def plotBar(df):
    ind = np.arange(len(df['name']))
    plt.rc('font', family='Gulim')
    fig, ax = plt.subplots()
    width = 0.8 / 4
    rect1 = ax.bar(ind-1*width, df['kor'], width, color='blue')
    rect2 = ax.bar(ind, df['eng'], width, color='red')
    rect3 = ax.bar(ind+1*width, df['math'], width, color='yellow')
    rect4 = ax.bar(ind+2*width, df['average'], width, color='black')
    plt.ylim(0,100, 10)
    ax.set_ylabel('Scores')
    ax.set_title('Scores by students')
    ax.set_xticklabels(df['name'])
    ax.legend((rect1[0], rect2[0], rect3[0], rect4[0]), ('국어','영어','수학','평균'))
    ax.set_xticks(ind + width)
    plt.show()

def data_statistics():
    data = select_data()
    df = pd.DataFrame(data, columns=['name', 'kor', 'eng', 'math'])
    dsum = df.sum(axis=1)
    davg = dsum/3
    df['sum'] = dsum
    df['average'] = davg.astype(int)
    df['rank'] = dsum.rank(ascending=False).astype(int)
    print(df)
    plotBar(df)
    #plt.plot(x1, df['kor'], x1, df['eng'], x1, df['math'], x1, df['average'])

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
7. 통계
8. 종료

메뉴를 선택하세요:""")
    return menu

def main_process():
    create_table()
    while True:
        menu = int(input_menu())
        print(menu)
        if menu == 8:
            break;
        if menu < 1 or menu > 7:
            continue
        if   menu == 1: data_input_manual()
        elif menu == 1: data_input()
        elif menu == 2: data_print('')
        elif menu == 3: data_delete()
        elif menu == 4: data_update()
        elif menu == 5: data_search()
        elif menu == 6: data_sort()
        elif menu == 7: data_statistics()
        menu = -1
    print("프로그램을 종료합니다.")

if __name__ == '__main__':
    main_process()

