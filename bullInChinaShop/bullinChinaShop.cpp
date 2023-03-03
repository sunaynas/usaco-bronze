#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > pieceOverlap(vector<vector<char> > &og,
                                    vector<vector<char> > &piece) {
  vector<pair<int, int> > overlaps;
  if (piece.size() > og.size() || piece[0].size() > og[0].size()) {
    // piece is bigger than og
    return overlaps;
  }

  // pos represents top left corner of piece
  pair<int, int> pos;
  //   cout << "using pos from index y = 0 to " << og.size() - piece.size()
  //        << " and x = 0  to " << og[0].size() - piece[0].size() << endl;

  for (int a = 0; a <= og.size() - piece.size(); a++) {
    for (int b = 0; b <= og[0].size() - piece[0].size(); b++) {
      pos = make_pair(a, b);
      /* FB::
      if (isOverlapping(og, piece, pos)) {
        overlaps.push_back(pos);
      }
      */
      // cout << "when pos is x =" << b << " y= " << a << endl;
      bool overlap = true;  // FB:: Could be just boolean
                        // Variable called overlaps and overlap are easy to miss
                        // use and make mistakes on use distinct names.
      for (int i = 0; i < piece.size(); i++) {
        for (int j = 0; j < piece[0].size(); j++) {
          if (piece[i][j] == '#' && '.' == og[pos.first + i][pos.second + j]) {
            // cout << "at x=" << pos.second + j << " and y=" << pos.first + i
            //      << " there is overlap of " << piece[i][j] << endl;
            overlap = false;
          }
        }
      }
      if (overlap) {
        overlaps.push_back(pos);
      }
    }
  }

  return overlaps;
}
bool originalCovered(vector<vector<char> > og, vector<vector<char> > pieceA,
                     vector<vector<char> > pieceB, pair<int, int> posA,
                     pair<int, int> posB) {
  int gridSize = og.size();
  vector<vector<char> > cp(gridSize);
  for (int i = 0; i < gridSize; ++i) {
    cp[i].resize(og[0].size());
    for (int j = 0; j < og[0].size(); ++j) {
      cp[i][j] = '.';
    }
  }
  for (int i = 0; i < pieceA.size(); ++i) {
    for (int j = 0; j < pieceA[i].size(); ++j) {
      cp[i + posA.first][j + posA.second] = pieceA[i][j];
    }
  }
  for (int i = 0; i < pieceB.size(); ++i) {
    for (int j = 0; j < pieceB[i].size(); ++j) {
      if (pieceB[i][j] == '#') {
        if (cp[i + posB.first][j + posB.second] == '#'){
          return false;
        } else 
        cp[i + posB.first][j + posB.second] = pieceB[i][j];
      }
    }
  }
  for (int i = 0; i < gridSize; ++i) {
    for (int j = 0; j < gridSize; ++j) {
      if (cp[i][j] != og[i][j]) return false;
    }
  }
  return true;
}
vector<vector<char> >  crop(vector<vector<char> >  obj) {
  // cout << "CALLING CROP FUNCTION" << endl;
  int gridSize = obj[0].size();
  int XLowerBound = 0, YLowerBound = 0, XUpperBound = gridSize - 1,
      YUpperBound = gridSize - 1;
  bool XUclear = true, XLclear = true, YUclear = true, YLclear = true;
  for (int a = 0; a < gridSize; a++) {
    for (int b = 0; b < gridSize; b++) {
      // obj[y][]
      if (obj[a][b] == '#') {  // obj[a][b] = x lowerbound -> & ^
        // cout << "# at row " << b << " column " << a << endl;
        XLclear = false;
      }
      if (obj[gridSize - a - 1][b] ==
          '#') {  // obj[gridsize-a][b]= x upperbound <- & ^
        XUclear = false;
      }
      if (obj[b][a] == '#') {  // obj[b][a] = y lowerbound ^ ->
        YLclear = false;
      }
      if (obj[b][gridSize - a - 1] ==
          '#') {  // obj[b][gridsize-a]= y upperbound down & ->
        // cout << "# at " << b << ", " << gridSize - a - 1 << endl;
        YUclear = false;
      }
    }
    // XUpperBound += XUclear;
    if (XUclear) {
      XUpperBound--;
    }
    if (XLclear) {
      XLowerBound++;
    }
    if (YLclear) {
      YLowerBound++;
    }
    if (YUclear) {
      YUpperBound--;
    }
  }
  //   cout << "X LOWER BOUND: " << XLowerBound << endl;
  //   cout << "X UPPER BOUND: " << XUpperBound << endl;
  //   cout << "Y LOWER BOUND: " << YLowerBound << endl;
  //   cout << "Y UPPER BOUND: " << YUpperBound << endl;

  vector<vector<char> >  objOut(XUpperBound - XLowerBound + 1);
  for (int i = XLowerBound; i <= XUpperBound; i++) {
    objOut[i - XLowerBound].resize(YUpperBound - YLowerBound + 1);
    for (int j = YLowerBound; j <= YUpperBound; j++) {
      objOut[i - XLowerBound][j - YLowerBound] = obj[i][j];
    }
  }

  return objOut;
}

pair<int, int> solve(vector<vector<char> >  og,
                     vector<vector<vector<char> > > pieces) {
  int numOfPieces = pieces.size();
  vector<vector<pair<int, int> > > piecesOverlap(numOfPieces);
  // cropping original
  og = crop(og);
  //   cout << "cropping og successful" << endl;
  // cropping pieces and finding their overlaps
  for (int i = 0; i < numOfPieces; i++) {
    pieces[i] = crop(pieces[i]);
    // cout << "cropping piece " << i << " successful" << endl;
    piecesOverlap[i] = pieceOverlap(og, pieces[i]);
    // cout << "finding overlaps of piece " << i << " successful" << endl;
  }
  // cout << "cropping pieces and finding overlaps successful" << endl;

  for (int i = 0; i < numOfPieces; i++) {
    // for each piece
    for (int k = i + 1; k < numOfPieces; k++) {
      // for each piece after it (you dont need to check it with the pieces
      // before because they already checked with this one)
      for (int j = 0; j < piecesOverlap[i].size(); j++) {
        // for each overlap of first  piece
        for (int l = 0; l < piecesOverlap[k].size(); l++) {
          // for each overlap of second piece
          if (originalCovered(og, pieces[i], pieces[k], piecesOverlap[i][j],
                              piecesOverlap[k][l])) {
            return make_pair(i + 1, k + 1);
          }
          // cout << "checking og covered successful" << endl;
        }
      }
    }
  }
  cout << "could not find pair" << endl;
}

#ifndef TESTING
int main() {
  int gridSize, numOfPieces;
  cin >> gridSize >> numOfPieces;
  vector<vector<char> > og(gridSize);
  vector<vector<vector<char> > > pieces(numOfPieces);

  // read original image
  for (int i = 0; i < gridSize; i++) {
    og[i].resize(gridSize);
    for (int j = 0; j < gridSize; j++) {
      cin >> og[i][j];
    }
  }
  // read pieces and store them in a vector
  for (int a = 0; a < numOfPieces; a++) {
    pieces[a].resize(gridSize);
    for (int i = 0; i < gridSize; i++) {
      pieces[a][i].resize(gridSize);
      for (int j = 0; j < gridSize; j++) {
        cin >> pieces[a][i][j];
      }
    }
  }
  pair<int, int> answ = solve(og, pieces);
  cout << answ.first << " " << answ.second;
  return 0;
}
#endif

bool originalCoveredSu(vector<vector<char> > og, vector<vector<char> > pieceA,
                       vector<vector<char> > pieceB, pair<int, int> posA,
                       pair<int, int> posB) {
  for (int y = 0; y < og.size(); y++) {
    for (int x = 0; x < og[0].size(); x++) {
      if (og[y][x] == '#') {
        bool covered = false;
        // checking if the pieces collide
        int piecesOverlap = 0;
        // cout << "row " << y << " column " << x
        //      << " is filled and needs to be covered" << endl;
        if (posA.first <= y && posA.first + pieceA.size() >= y &&
            posA.second <= x && posA.second + pieceA[0].size() >= x) {
          // in the range of first piece
          //   cout << "this position is in piece A from y is " << posA.first
          //        << " to " << posA.first + pieceA.size() << " and x is "
          //        << posA.second << " to " << posA.second + pieceA[0].size()
          //        << endl
          //        // y - pos.first, x- pos.second is spot on piece that ur
          //        looking
          //        // at
          //        << "position y=" << y << " x = " << x
          //        << " is equivalent to pos y= " << y - posA.first
          //        << " x=" << x - posA.second << endl;
          if (pieceA[y - posA.first][x - posA.second] == '#') {
            // cout << "this position is also filled on the piece, covering the
            // "
            //         "original"
            //      << endl;
            covered = true;
            piecesOverlap++;
          }
        }
        if (posB.first <= y && posB.first + pieceB.size() >= y &&
            posB.second <= x && posB.second + pieceB[0].size() >= x) {
          // in the range of second piece
          //   cout << "this position is in piece B from y is " << posB.first
          //        << " to " << posB.first + pieceB.size() << " and x is "
          //        << posB.second << " to " << posB.second + pieceB[0].size()
          //        << endl
          //        // y - pos.first, x- pos.second is spot on piece that ur
          //        // looking at
          //        << "position y=" << y << " x = " << x
          //        << " is equivalent to pos y= " << y - posB.first
          //        << " x=" << x - posB.second << endl;
          if (pieceB[y - posB.first][x - posB.second] == '#') {
            // cout << "this position is also filled on the piece, covering the
            // "
            //         "original"
            //      << endl;
            covered = true;
            piecesOverlap++;
          }
        }
        if (piecesOverlap == 2 || covered == false) {
          //   cout << endl
          //        << endl
          //        << "THE PIECES OVERLAPPED OR THIS FILLED SPOT " << x << ", "
          //        << y
          //        << " WAS NOT COVERED" << endl;
          return false;
        }
      }
    }
  }
  return true;
}
