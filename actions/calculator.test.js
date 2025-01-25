// calculator.test.js
const { add, subtract, multiply, divide } = require("./calculator");

describe("Calculator functions", () => {
  test("adds two numbers", () => {
    expect(add(2, 3)).toBe(5);
    expect(add(-1, -1)).toBe(-2);
    expect(add(0, 0)).toBe(0);
  });

  test("subtracts two numbers", () => {
    expect(subtract(5, 3)).toBe(2);
    expect(subtract(0, 3)).toBe(-3);
    expect(subtract(10, 10)).toBe(0);
  });

  test("multiplies two numbers", () => {
    expect(multiply(2, 3)).toBe(6);
    expect(multiply(-2, 3)).toBe(-6);
    expect(multiply(0, 100)).toBe(0);
  });

  test("divides two numbers", () => {
    expect(divide(6, 3)).toBe(2);
    expect(divide(-6, 3)).toBe(-2);
    expect(divide(0, 1)).toBe(0);
  });

  test("throws error when dividing by zero", () => {
    expect(() => divide(1, 0)).toThrow("Cannot divide by zero");
  });
});
