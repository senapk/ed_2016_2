#include <lib/pen.h>

void arvore(Pen &p, float lado){
    if(lado < 5){
        return;
    }
    float ang = 120;

    p.setColor(200, 100, 100);

    for(int i = 0; i < 3; i++){
        p.walk(lado);
        p.right(120);
        arvore(p, (lado / 2));
    }






}

void fractal(){
    Pen p(800, 700);
    //coloca o pincel na posicao x 300 y 500
    p.setXY(100, 100);

    //faz o pincel apontar pra direita
    p.setHeading(0);
    //se speed = 0 entao ele faz o mais rapido possivel
    //se foi a partir de 1 ele controla a velocidade
    p.setSpeed(20);
    p.setThickness(3);
    arvore(p, 600);





    //espera clicar no botao de fechar
    p.wait();
}

int main(){
    fractal();
    return 0;
}








