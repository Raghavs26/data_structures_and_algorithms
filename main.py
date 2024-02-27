from Solution import *

if __name__ == "__main__":
    mobile_mediator = stockMediator()
    mobile_purchase = purchaseColleague(mobile_mediator)
    mobile_warehouse = warehouseColleague(mobile_mediator)
    mobile_sales = salesColleague(mobile_mediator)
    mobile_mediator.setPurchase(mobile_purchase)
    mobile_mediator.setWarehouse(mobile_warehouse)
    mobile_mediator.setSales(mobile_sales)

    mobile_warehouse.setThreshold(200)
    mobile_purchase.buyStuff(300)
    mobile_sales.sellStuff(120)