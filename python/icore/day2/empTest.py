class Employee:
    def __init__(self, name, addr):
        self.name= name
        self.addr = addr
    def ShowYourName(self):
        print("name:", self.name)
    def ShowYourAddr(self):
        print("addr:", self.addr)
        
    def empProc(self):  #template method
        self.ShowYourName()
        self.ShowYourAddr()
        self.ShowSalaryInfo()
        
    def GetPay(self):
        pass
    def ShowSalaryInfo(self):
        pass
    
class Permanent(Employee):
    def __init__(self, name, addr,salary):
        super().__init__(name, addr)
        self.salary = salary    
    def GetPay(self):
        return self.salary
    def ShowSalaryInfo(self):
        print("영구직급여:", self.salary)

class Temporary(Employee):
    def __init__(self, name, addr, day, pay):
        super().__init__(name, addr)
        self.day = day
        self.pay = pay
    def GetPay(self):
        return self.day * self.pay
    def ShowSalaryInfo(self):
        print("임시직급여:", self.GetPay())
        
class Manager(Employee):
    def __init__(self, name, addr, salary, dept):
        super().__init__(name, addr)
        self.salary = salary
        self.dept = dept
    def GetPay(self):
        return self.salary
    def ShowSalaryInfo(self):
        print("관리급여:", self.salary," 부서:",self.dept)
        self.showDept()
    
    def showDept(self):
        print("부서:", self.dept)

if __name__ == '__main__':
    emp = Permanent("홍길동","서울시", 5000)
    emp.empProc()
    
    emp = Temporary("임꺽정","부산시",10, 1000)
    emp.empProc()
    
    emp = Manager("김철수","광주시", 6000,"영업직")
    emp.empProc()
    
# class EmpContext:
#     def __init__(self):
#         self.pEmp =0
#     def ChangeEmp(self, pEmp):
#         self.pEmp = pEmp
#     def EmpInfo(self):
#         self.pEmp.ShowYourName()
#         self.pEmp.ShowYourAddr()
#         self.pEmp.ShowSalaryInfo()
# if __name__ == '__main__':
#     empContext = EmpContext()
#     empContext.ChangeEmp(Permanent("홍길동","서울시", 5000))
#     empContext.EmpInfo()
# 
#     empContext.ChangeEmp(Temporary("임꺽정","부산시",10, 1000))
#     empContext.EmpInfo()
# 
#     empContext.ChangeEmp(Manager("김철수","광주시", 6000,"영업직"))
#     empContext.EmpInfo()
    
#     manager = Manager("김철수","광주시", 6000,"영업직")
#     manager.ShowYourName()
#     manager.ShowYourAddr()
#     manager.ShowSalaryInfo()
#     temp = Temporary("임꺽정","부산시",10, 1000)
#     temp.ShowYourName()
#     temp.ShowYourAddr()
#     temp.ShowSalaryInfo()
#     permanent = Permanent("홍길동","서울시", 5000)
#     permanent.ShowYourName()
#     permanent.ShowYourAddr()
#     permanent.ShowSalaryInfo()










    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    