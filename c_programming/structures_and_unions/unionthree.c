enum Type { INTS, FLOATS, DOUBLE };
struct S
{
  Type s_type;
  union
  {
    int s_ints[2];
    float s_floats[2];
    double s_double;
  };
};

void do_something(struct S *s)
{
  switch(s->s_type)
  {
    case INTS:  // do something with s->s_ints
      break;

    case FLOATS:  // do something with s->s_floats
      break;

    case DOUBLE:  // do something with s->s_double
      break;
  }
}