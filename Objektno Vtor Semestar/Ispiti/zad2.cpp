#include<iostream>
#include<cstring>
using namespace std;

enum AudioFormat{ mp3, wav, ogg, flac };
enum VideoCompression{ x264, Theora, AV1 };

class MediaSegment{
    protected:
        char title[100], author[100]; int duration{0}, size{0};
    public:
        MediaSegment(){}
        MediaSegment(char *t, char *a, int d, int s){
            strcpy(this->title,t); strcpy(this->author,a); this->duration = d; this->size = s;
        }
        MediaSegment(const MediaSegment &other){
            if(this != &other){
                strcpy(this->title, other.title); strcpy(this->author, other.author); this->duration = other.duration; this->size = other.size;
            }
        }
        MediaSegment &operator=(const MediaSegment &other){
            if(this != &other){
                strcpy(this->title, other.title); strcpy(this->author, other.author); this->duration = other.duration; this->size = other.size;
            } return *this;
        }
        ~MediaSegment(){}
        virtual double price() const = 0;
};

class AudioRecording : virtual public MediaSegment{
    protected:
        AudioFormat format; short channels;
    public:
        AudioRecording(){}
        AudioRecording(char *t,  char *a, int d, int s, int f, int c):MediaSegment(t, a, d, s){
            this->format = (AudioFormat) f; this->channels = c;
        }
        double price() const {
            double prod = duration * channels;
            if(format == flac){ prod *= 1.5; }
            return prod;
        }
        friend ostream &operator<<(ostream &out, const AudioRecording &other){
            return out<< other.title<<" - "<<other.author<<" - "<<other.duration<<" - "<<other.size<<" - "<<other.price();
        }
};

class VideoRecording : virtual public MediaSegment{
    protected:
        VideoCompression compression; int width{0};
    public:
        VideoRecording(){}
        VideoRecording(char *t, char *a, int d, int s, int w, int c):MediaSegment(t, a, d, s){
            this->width = w; this->compression = (VideoCompression) c;
        }
        ~VideoRecording(){}

        double price() const{
            double price;
            if(width < 1920){ price = 100 * duration; }
            else{ price = 170 * duration; }

            if(compression == x264){ price *= 1.5; }
            else if(compression == Theora){ price *= 0.9; }
            return price;
        }

        friend ostream &operator<<(ostream &out, VideoRecording &other){
            return out<<other.title<<" - "<<other.author<<" - "<<other.duration<<" - "<<other.size<<" - "<<other.width<<" - "<<other.price();
        }
};

class MusicVideo : public AudioRecording, public VideoRecording{
    private:
        char *date{nullptr};
    public:
        MusicVideo(){}
        MusicVideo(char *t, char *a, int d, int s, int f, short c, int w, int comp, char *date):MediaSegment(t,a,d,s){
            this->format = (AudioFormat) f; this->channels = c; this->width = w; this->compression = (VideoCompression) comp; 
            this->date = new char[strlen(date)]; strcpy(this->date,date);
        }
        ~MusicVideo(){}

        double price() const{
            double res = AudioRecording::price() + VideoRecording::price();
            if(strcmp(date + 4,"2010") > 0){ res *= 1.3; } return res;
        }

        friend ostream &operator<<(ostream &out, const MusicVideo &other){
            return out<<other.title<<" - "<<other.author<<" - "<<other.date<<" - "<<other.duration<<" - "<<other.price();
        }
};

double total_price(MediaSegment **arr, int num){ double sum = 0; for(int i=0; i<num; i++){ sum += arr[i]->price(); } return sum; }

MusicVideo cheapest_music_video(MediaSegment **arr, int num){
    MusicVideo *min = nullptr;
    for(int i=0; i<num; i++){
        MusicVideo *cast = dynamic_cast<MusicVideo *>(arr[i]);
        if(cast){ 
            if(min == nullptr){ min = cast; }
            else if( cast->price() < min->price()){ min = cast; }
        }
    } return *min;
}

int main() {

  int test_case_num;
  cin>>test_case_num;


  // for MediaSegment
  char title[100];
  char author[1000];
  unsigned int size;
  unsigned int duration;


  // for AudioRecording
  //-------------------
  unsigned short channels;

  // AudioFormat:
  // 0 - mp3
  // 1 - wav
  // 2 - ogg
  // 3 - flac
  unsigned short format;


  // for VideoRecording
  //-------------------
  unsigned short width;

  // VideoCompression:
  // 0 - x264
  // 1 - Theora
  // 2 - AV1
  int compression;


  // for MusicVideo
  //-------------------
  char publication_date[9];


  if (test_case_num == 1){
    cout<<"Testing class AudioRecording and operator<<"<<std::endl;
    cin.get();
    cin.getline(title,100);
    cin.getline(author, 100);
    //cin.get();
    cin >> duration >> size;
    cin >> format >> channels;

    AudioRecording a(title, author, duration, size, format, channels);

    cout<<a;

  }

  else if (test_case_num == 2){
    cout<<"Testing class VideoRecording and operator<<"<<std::endl;
    cin.get();
    cin.getline(title,100);
    cin.getline(author, 100);
    //cin.get();
    cin >> duration >> size;
    cin >> width >> compression;

    VideoRecording v(title, author, duration, size, width, compression);

    cout<<v;

  }

  else if (test_case_num == 3){
    cout<<"Testing class MusicVideo and operator<<"<<std::endl;

    cin.get();
    cin.getline(title,100);
    cin.getline(author, 100);
    //cin.get();
    cin >> duration >> size;

    cin >> format >> channels;
    cin >> width >> compression;

    cin.get();
    cin.getline(publication_date, 9);
    MusicVideo mv(title, author, duration, size, format, channels, width, compression, publication_date);

    cout << mv;
  }

  else if (test_case_num == 4){
    cout<<"Testing function: total_price "<<std::endl;

    MediaSegment ** m;

    int num_media_segments;
    cin >> num_media_segments;

    // 1 - AudioRecording
    // 2 - VideoRecording
    // 3 - MusicVideo
    short media_type;

    m = new MediaSegment*[num_media_segments];

    for (int i=0; i<num_media_segments; i++) {

      cin >> media_type;

      cin.get();
      cin.getline(title,100);
      cin.getline(author, 100);
      //cin.get();
      cin >> duration >> size;

      switch(media_type) {
      case 1:
              cin >> format >> channels;
              m[i] = new AudioRecording(title, author, duration, size, format, channels);
          break;
      case 2:
              cin >> width >> compression;
              m[i] = new VideoRecording(title, author, duration, size, width, compression);
          break;
      case 3:
              cin >> format >> channels;
              cin >> width >> compression;
              cin.get();
              cin.getline(publication_date, 9);
              m[i] = new MusicVideo(title, author, duration, size, format, channels, width, compression, publication_date);
          break;
      }
    }

    //for (int i=0;i<num_media_segments; i++){
    //    cout << *m[i];
    //}

    cout<< "Total price is: " << total_price(m, num_media_segments);

    delete [] m;

  }
  else if (test_case_num == 5){
    cout<<"Testing function: cheapest_music_video "<<std::endl;

    MediaSegment ** m;

    int num_media_segments;
    cin >> num_media_segments;

    // 1 - AudioRecording
    // 2 - VideoRecording
    // 3 - MusicVideo
    short media_type;

    m = new MediaSegment*[num_media_segments];

    for (int i=0; i<num_media_segments; i++) {

      cin >> media_type;

      cin.get();
      cin.getline(title,100);
      cin.getline(author, 100);
      //cin.get();
      cin >> duration >> size;

      switch(media_type) {
      case 1:
              cin >> format >> channels;
              m[i] = new AudioRecording(title, author, duration, size, format, channels);
          break;
      case 2:
              cin >> width >> compression;
              m[i] = new VideoRecording(title, author, duration, size, width, compression);
          break;
      case 3:
              cin >> format >> channels;
              cin >> width >> compression;
              cin.get();
              cin.getline(publication_date, 9);
              m[i] = new MusicVideo(title, author, duration, size, format, channels, width, compression, publication_date);
          break;
      }
    }

    cout << cheapest_music_video(m, num_media_segments);

    delete [] m;
  }

  return 0;
}
