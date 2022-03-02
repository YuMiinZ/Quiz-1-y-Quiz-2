//Elaborado por Ericka Yu Min

#include <iostream>
#include <list>
#include <vector>
using namespace std;

enum tipoMedia{VIDEO, AUDIO, FOTO};

class Media{
    private:
        tipoMedia tipo;
        string autor, ruta, fecha;
    public:
        Media(){};
        Media(tipoMedia tipoIngr, string autorIngr, string rutaIngr, string fechaIngr):tipo(tipoIngr),autor(autorIngr), ruta(rutaIngr),fecha(fechaIngr){};
        void setTipo(tipoMedia tipoIngr){tipo=tipoIngr;};
        void setAutor(string autorIngr){autor=autorIngr;};
        void setFecha(string fechaIngr){fecha=fechaIngr;};
        void setRuta(string rutaIngr){ruta=rutaIngr;};
        string getTipo(){if(tipo==0){return "Video";}return ((tipo==1)?"Audio":"Foto");};
        string getAutor(){return autor;};
        string getFecha(){return fecha;};
        string getRuta(){return ruta;};
        string toString(){string tipoMedia; if(tipo==0){tipoMedia= "Video";}else{(tipoMedia=(tipo==1)?"Audio":"Foto");};
        return "\nTipo Media: " + tipoMedia + "\nAutor: "+ autor + "\nRuta: " + ruta + "\nFecha: " +fecha+ "\n";};
};

class Noticia{
    protected:
        string titulo, fecha, reportero;
    public:
        //Metodos constructores
        Noticia(){};
        Noticia(string tituloIngr, string fechaIngr, string reporteroIngr):titulo(tituloIngr),fecha(fechaIngr),reportero(reporteroIngr){};
        //Setters y getters
        void setTitulo(string tituloIngr){titulo=tituloIngr;};
        void setFecha(string fechaIngr){fecha=fechaIngr;};
        void setReportero(string reporteroIngr){reportero=reporteroIngr;};
        string getTitulo(){return titulo;};
        string getFecha(){return fecha;};
        string getReportero(){return reportero;};
        //Metodo virtual puro o abstracto
        virtual string getInfo()=0;
};

class NoticiaPaper:public Noticia{
    private:
        string ruta;
    public:
        NoticiaPaper(){};
        NoticiaPaper(string, string, string, string);
        void setRuta(string rutaIngr){ruta=rutaIngr;};
        string getRuta(){return ruta;};
        string getInfo(){return "\nTitulo: " + Noticia::titulo + "\nFecha: " + Noticia::fecha + "\nReportero: " + Noticia::reportero +
        "\nRuta: " + ruta + "\n";};
};

NoticiaPaper::NoticiaPaper(string titulo,string fecha, string reportero, string rutaIngr): Noticia(titulo,fecha,reportero){
    ruta=rutaIngr;
}

class NoticiaDigital: public Noticia{
    private:
        list<Media> listaMedia;
    public:
        NoticiaDigital(){};
        NoticiaDigital(string, string, string, list<Media>);
        void setLista(list<Media> listaIngr){listaMedia=listaIngr;};
        void addLista(Media nuevaMedia){listaMedia.push_front(nuevaMedia);};
        list<Media> getLista(){return listaMedia;};
        string getInfo(){string lista; for(auto pos=listaMedia.begin();pos!=listaMedia.end();pos++){Media mediaTemp=*pos; lista+=mediaTemp.toString();}
            return "\nTitulo: " + Noticia::titulo + "\nFecha: " + Noticia::fecha + "\nReportero: " + Noticia::reportero +
            "\n"+lista + "\n";};
};

NoticiaDigital::NoticiaDigital(string titulo,string fecha, string reportero, list<Media> listaMediaIngr): Noticia(titulo,fecha,reportero){
    listaMedia=listaMediaIngr;
}

class NoticiaRadio: public Noticia{
    private:
        string url;
    public:
        NoticiaRadio(){};
        NoticiaRadio(string, string, string, string);
        void setUrl(string urlIngr){url=urlIngr;};
        string getUrl(){return url;};
        string getInfo(){return "\nTitulo: " + Noticia::titulo + "\nFecha: " + Noticia::fecha + "\nReportero: " + Noticia::reportero +
        "\nUrl:  " + url + "\n";};
};

NoticiaRadio::NoticiaRadio(string titulo,string fecha, string reportero, string urlIngr): Noticia(titulo,fecha,reportero){
    url=urlIngr;
}

int main(){
    cout<<"Mostrando Datos...\n";
    list<Media> listaMedia;
    Media media1(AUDIO,"Marcos","audios/audioNotiDigital","02/03/2022");
    Media media2(FOTO,"Elizabeth","foto/fotoNotiDigital","02/03/2022");
    Media media3(VIDEO,"Jhon","video/videoNotiDigital","08/02/2022");
    listaMedia.push_back(media1);
    listaMedia.push_back(media2);
    listaMedia.push_back(media3);

    vector<Noticia*> listaNoticias{new NoticiaPaper("Titulo1","27/02/2022","Tony","/carpeta1/imagenes"),
    new NoticiaDigital("Titulo2","30/02/2022","Marta",listaMedia), new NoticiaRadio("Titulo3","17/06/2015","Tennessee","www.patitoMix.es")};

    for(size_t pos=0;pos<listaNoticias.size();pos++){
        cout<<"----------------------------------------------------------------------------------------------------";
        cout<<"\n"+listaNoticias.at(pos)->getInfo()<<"\n";
    }
}


