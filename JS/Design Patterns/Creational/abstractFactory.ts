interface Chair {
    sit : () => void;
}

class ModernChair implements Chair {
    public sit () : void {
        console.log(" I am siting on modern chair");
    }
}

class ArtChair implements Chair {
    public sit () : void {
        console.log(" I am siting on art chair");
    }
}

interface Table {
    draw: () => void;
}

class ModernTable implements Table{
    public draw (): void {
        console.log("I am drawing in modern table ");
    }
}


class ArtTable implements Table{
    public draw (): void {
        console.log("I am drawing in art table ");
    }
}

interface AbstractFactory {
    createChair : () => Chair;
    createTable : () => Table;
}

class ModernFactory implements AbstractFactory {
    public createChair () : Chair {
        return new ModernChair();
    }
    public createTable () : Table {
        return new ModernTable();
    }
}


class ArtFactory implements AbstractFactory {
    public createChair () : Chair {
        return new ArtChair();
    }
    public createTable () : Table {
        return new ArtTable();
    }
}

new ArtFactory().createChair().sit();
new ModernFactory().createChair().sit();