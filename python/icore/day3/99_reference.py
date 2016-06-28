# -*- coding:ms949 -*-
import sqlite3

def printMenu():
    print("="*22)
    print("���������� ó��")
    print("="*22)
    print("1. �Է�", "2. ����", "3. ����", "4. ����", "5. �˻�", "6. ����", "7. ����", "8. ����", sep='\n')
    return input("�޴��� �����ϼ��� : ")

def doInput(cur):
    cont = 'y'
    while(cont == 'y'):
        name    = input("�̸� : ")
        korean  = input("���� : ")
        english = input("���� : ")
        math    = input("���� : ")
        q = "insert into scores(name, korean, english, math) values(?, ?, ?, ?)"
        cur.execute(q, (name, korean, english, math))
        cont = input("��� �Է��Ͻðڽ��ϱ�(y/n)?")

def doShow(cur):
    print("=" * 36)
    print("%10s%10s%10s%10s%10s%10s"%('�̸�','����','����','����','����','���'))
    print("=" * 36)
    q = "select * from scores"
    cur.execute(q)
    ks = 0
    es = 0
    ms = 0
    c = 0
    for n, k, e, m in cur:
        print("%10s%9d%6d%6d%7d%5d"%(n,k,e,m,(k+e+m),(k+e+m)/3))
        ks += k
        es += e
        ms += m
        c += 1
    print("=" * 36)
    if c != 0:
        print("%7s%8d%6d%6d"%("���� ���",ks/c, es/c, ms/c))

def doDelete(cur):
    name = input("������ �̸��� �Է��ϼ��� : ")
    q = "delete from scores where name=?"
    cur.execute(q, (name,))

def doUpdate(cur):
    name = input("������ �̸��� �Է��ϼ��� : ")
    q = "select * from scores where name=?"
    cur.execute(q, (name,))
    lst = cur.fetchall()
    if len(lst) != 0 :
        uname   = input("�̸� (%s): "%(lst[0][0]))
        korean  = input("���� (%d): "%(lst[0][1]))
        english = input("���� (%d): "%(lst[0][2]))
        math    = input("���� (%d): "%(lst[0][3]))
        q = "update scores set name=?, korean=?, english=?, math=? where name=?"
        cur.execute(q, (uname, korean, english, math, name))
    
def doSearch(cur):
    name = input("�̸��� �Է��ϼ��� : ")
    q = "select * from scores where name=?"
    cur.execute(q, (name,))
    print("=" * 36)
    print("%10s%10s%10s%10s%10s%10s"%('�̸�','����','����','����','����','���'))
    print("=" * 36)
    for n, k, e, m in cur:
        print("%10s%9d%6d%6d%7d%5d"%(n,k,e,m,(k+e+m),(k+e+m)/3))

def doSort(cur):
    print("=" * 36)
    print("%10s%10s%10s%10s%10s%10s"%('�̸�','����','����','����','����','���'))
    print("=" * 36)
    q = "select * from scores order by name"
    cur.execute(q)
    ks = 0
    es = 0
    ms = 0
    c = 0
    for n, k, e, m in cur:
        print("%10s%9d%6d%6d%7d%5d"%(n,k,e,m,(k+e+m),(k+e+m)/3))
        ks += k
        es += e
        ms += m
        c += 1
    print("=" * 36)
    if c != 0:
        print("%7s%8d%6d%6d"%("���� ���",ks/c, es/c, ms/c))


def doCommit(cur):
    yn = input("�����ͺ��̽��� �����Ͻðڽ��ϱ�(y/n)?")

def createTable(cur):
    try :
        q = "create table if not exists scores(name text, korean int, english int, math int)"
        cur.execute(q)
    except Exception as err:
        print("err:", err)

def main():
    dictMenu = {'1':doInput, '2':doShow, '3':doDelete, '4':doUpdate, '5':doSearch, '6':doSort, '7':doCommit}

    try :
        db = sqlite3.connect('homework.db') # Create a database file if it is not available or just connect.
        cur = db.cursor()
        createTable(cur)
        while(1):
            menu = printMenu()
            func = dictMenu.get(menu, '8')
            if func == '8' : break;
            func(cur)
        db.commit()
        db.close()
    except Exception as err:
        print("err:", err)
    
    print("��")    

if __name__ == '__main__':
    main()
