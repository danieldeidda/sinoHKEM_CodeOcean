//
// $Id$
//

/*!
  \file
  \ingroup utilities

  \brief A utility that just fills the projection data with 1

  \author Kris Thielemans

  $Date$
  $Revision$
*/


#include "utilities.h"
#include "interfile.h"
#include "ProjDataFromStream.h"
#include "SegmentByView.h"
#include "tomo/Succeeded.h"

#include <iostream> 
#include <fstream>

#ifndef TOMO_NO_NAMESPACES
using std::cerr;
using std::endl;
using std::fstream;
using std::ifstream;
using std::cout;
#endif


USING_NAMESPACE_TOMO

int main(int argc, char *argv[])
{ 
  
  if(argc!=2) 
  {
    cerr<<"Usage: " << argv[0] << " projdata_file\n"
       	<< endl; 
  }

  shared_ptr<ProjData> projdata_ptr = 
  ProjData::read_from_file(argv[1], ios::in|ios::out);
  

  for (int segment_num=projdata_ptr->get_min_segment_num();
       segment_num<=projdata_ptr->get_max_segment_num();
       ++segment_num)
    {
      SegmentByView<float> segment = projdata_ptr->get_empty_segment_by_view(segment_num,false);
      segment.fill(1);
      projdata_ptr->set_segment(segment);
    }
  return EXIT_SUCCESS;

}
