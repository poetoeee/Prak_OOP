class Goose {
    private String name;
    private int honk;

    public Goose(){
        this.name = "Horrible";
        this.honk = 1;
    }

    public Goose(String name, int honk){
        this.name = name;
        this.honk = honk;
    }

    public void steal(String thing){
        System.out.println(this.name + " steals " + thing);
    }

    public String toString(){
        String s = name + " goose";
        s+=" says ";
        for (int i=0; i<honk-1; i++){
            s += "honk ";
        }
        s+="honk";
        return s;
    }
    
}


