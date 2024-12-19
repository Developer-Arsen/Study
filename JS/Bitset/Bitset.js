class BitSet {
  constructor() {
    this.bitVec = new Uint32Array(240007);
    this.splitter = 32;
    this.slicesCount = 0;
  }

  getConcreteSlice(pos) {
    if (pos == 0 || !this.isEmpty()) return 0;
    if (pos < 0) throw RangeError("wrong argument");

    const shiftLeft = pos % 32 == 0 ? 1 : 0;
    return parseInt(pos / this.splitter) - shiftLeft;
  }

  getConcreteSlicePos(pos) {
    return pos % 32;
  }

  setBit(pos, val) {
    let concreteSlice = this.getConcreteSlice(pos);
    let concretePos = this.getConcreteSlicePos(pos);
  }
  getBit(pos) {}

  isEmpty() {
    return this.bitVec.length === 0;
  }
}

let bs = new BitSet();
bs.setBit(33, 1);
