class colleague():
    mediator = None

    def __init__(self, mediator):
        self.mediator = mediator


class purchaseColleague(colleague):
    def buyStuff(self, num):
        # write your code here

    def getNotice(self, content):
        print("PURCHASE:Get Notice--%s" % content)


class warehouseColleague(colleague):
    total = 0
    threshold = 100

    def setThreshold(self, threshold):
        self.threshold = threshold

    def isEnough(self):
        if self.total < self.threshold:
            # write your code here
        else:
            return True

    def inc(self, num):
        # write your code here

        self.isEnough()

    def dec(self, num):
        # write your code here
        
        self.isEnough()


class salesColleague(colleague):
    def sellStuff(self, num):
        print("SALES:Sell %s" % num)
        self.mediator.execute("sell", num)

    def getNotice(self, content):
        print("SALES:Get Notice--%s" % content)


class abstractMediator():
    purchase = ""
    sales = ""
    warehouse = ""

    def setPurchase(self, purchase):
        self.purchase = purchase

    def setWarehouse(self, warehouse):
        self.warehouse = warehouse

    def setSales(self, sales):
        self.sales = sales

    def execute(self, content, num):
        pass


class stockMediator(abstractMediator):
    def execute(self, content, num):
        print
        "MEDIATOR:Get Info--%s" % content
        if content == "buy":
            # write your code here
        elif content == "increase":
            # write your code here
        elif content == "decrease":
            # write your code here
        elif content == "warning":
            # write your code here
        elif content == "sell":
            # write your code here
        else:
            pass