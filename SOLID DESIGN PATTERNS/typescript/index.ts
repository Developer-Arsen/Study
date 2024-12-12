import Singleton from "./Creational/Singleton";

console.log(Singleton());
abstract class PaymentProcessor {
  abstract processPayment(amount: number): void;
}

class CreditCardProcessor extends PaymentProcessor {
  processPayment(amount: number): void {
    console.log(`Processing credit card payment - ${amount}`);
  }
}

class DebitCardProcessor extends PaymentProcessor {
  processPayment(amount: number): void {
    console.log(`Processing Debit card payment - ${amount}`);
  }
}

class PayPalProcessor extends PaymentProcessor {
  processPayment(amount: number): void {
    console.log(`Processing Paypal card payment - ${amount}`);
  }
}

function executePayments(
  paymentProcessor: PaymentProcessor,
  amount: number,
): void {
  paymentProcessor.processPayment(amount);
}

executePayments(new PayPalProcessor(), 100);
executePayments(new DebitCardProcessor(), 200);
executePayments(new CreditCardProcessor(), 300);
