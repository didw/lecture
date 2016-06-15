class Strategy:
    def AlorithmInterface(self):
        pass

class ConcreteStrategyA(Strategy):
    def AlorithmInterface(self):
        print("Processed by Strategy A")

class ConcreteStrategyB(Strategy):
    def AlorithmInterface(self):
        print("Processed by Strategy B")

class ConcreteStrategyC(Strategy):
    def AlorithmInterface(self):
        print("Processed by Strategy C")

class Context:
    def __init__(self):
        self.pStrategy =0
    def ChangeStrategy(self, pStrategy):
        self.pStrategy= pStrategy
    def ContextInterface(self):
        self.pStrategy.AlorithmInterface()
if __name__ == '__main__':
    context = Context()
    context.ChangeStrategy( ConcreteStrategyA() )
    context.ContextInterface()
    context.ChangeStrategy( ConcreteStrategyB() )
    context.ContextInterface()
    context.ChangeStrategy( ConcreteStrategyC() )
    context.ContextInterface()




