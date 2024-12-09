interface Shape {
  area(): number;
  perimiter(): number;
}

class Circle implements Shape {
  constructor(private radius: number) {
    this.radius = radius;
  }

  area(): number {
    return Math.PI * this.radius * this.radius;
  }

  perimiter(): number {
    return 2 * Math.PI * this.radius;
  }
}

const a = new Circle(2);

console.log(a.area());
