const test = () => {
  class Loger {
    private static instance_: Loger;
    private constructor() {}

    public static getInstance(): Loger {
      if (!Loger.instance_) {
        Loger.instance_ = new Loger();
      }
      return Loger.instance_;
    }
    log(): void {
      console.log("log in log");
    }
  }

  const logger = Loger.getInstance();
  const logger2 = Loger.getInstance();
  logger.log();
  logger2.log();
  console.log(logger == logger2);
};

export default test;
