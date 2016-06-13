ADDR = []

def process():
    message = """\n1.Input\n2.Output\n3.Search\n4.End\nChoose menu above:"""
    while 1:
        menu = 0
        while menu < 1 or 4 < menu:
            menu = int(input(message))
        if menu == 1:
            Input()
        elif menu == 2:
            Output()
        elif menu == 3:
            Search()
        elif menu == 4:
            End()
            exit()

def Input():
    print('\nInput')
    adr = dict()
    adr['name'] = input("Name:")
    adr['age'] = int(input("Age:"))
    adr['addr'] = input("Address:")
    ADDR.append(adr)
    cont = ''
    while not(cont == 'y' or cont == 'Y' or cont == 'n' or cont == 'N'):
        cont = input("Keep enter?(y/n)")
    if cont == 'y' or cont == 'Y':
        Input()

def Output():
    print('\n--------------Output----------------')
    print('      Name   Age         Address')
    print('------------------------------------')
    for d in ADDR:
        print("{name:>10} {age:4}     {addr}".format(**d))
    print('------------------------------------')

def Search():
    in_name = input("Input name:")
    print('\n--------------Search----------------')
    print('      Name   Age         Address')
    print('------------------------------------')
    for d in ADDR:
        if d['name'] == in_name:
            print("{name:>10} {age:4}     {addr}".format(**d))
    print('------------------------------------')

def End():
    print('\nProgram ends')

if __name__ == '__main__':
    process()