import unittest

def my_sum(a,b):
    return a+b

def my_mul(a,b):
    return a*b

class My:
    def __init__(self, x, y):
        self.a = x
        self.b = y

class MyUnitTest1(unittest.TestCase):
    def setUp(self):
        unittest.TestCase.setUp(self)
        print("Test My Class Begin")
    def tearDown(self):
        unittest.TestCase.tearDown(self)
        print("Test My Class End")
    def test_my_a(self):
        obj = My(20,30)
        self.assertTrue(obj.a == 20, "test My class member a")
    def test_my_b(self):
        obj = My(20,30)
        self.assertTrue(obj.b == 30, "test My class member b")
        

class MyUnitTest2(unittest.TestCase):
    def setUp(self):
        unittest.TestCase.setUp(self)
        print("Test Function Begin")
    def tearDown(self):
        unittest.TestCase.tearDown(self)
        print("Test Function End")
    def test_my_sum(self):
        rst = my_sum(3,4)
        self.assertEqual(rst, 7, "test sum")
    def test_my_mul(self):
        rst = my_mul(3,4)
        self.assertEqual(rst, 12, "test mul")
        

def main3():
    suite = unittest.TestSuite()
    suite.addTest(MyUnitTest1('test_my_a'))
    suite.addTest(MyUnitTest2('test_my_sum'))
    unittest.TextTestRunner(verbosity=2).run(suite)        

def main2():    
    suite = unittest.TestLoader().loadTestsFromTestCase(MyUnitTest1)
    unittest.TextTestRunner(verbosity=2).run(suite)        

def main1():
    unittest.main()
    
if __name__ == '__main__':
    main3()