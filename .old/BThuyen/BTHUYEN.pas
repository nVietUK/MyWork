const fi = 'BTHUYEN.INP';
      fo = 'BTHUYEN.OUT';
var n, i, m, u, v : integer;
    a : array[1..250,1..250] of 0..1;
    q : array[1..250] of integer;
    free : array[1..250] of boolean;
    ok : boolean;
procedure bfs(u:integer);
var  first, last, v : integer;
begin
  first:=1;
  last:=1;
  q[first]:=u;
  free[u]:=false;
  repeat
    u:=q[first];
    inc(first);
    for v:=1 to n do
    if free[v] and (a[u,v]=1) then
      begin
        inc(last);
        q[last]:=v;
        free[v]:=false;
      end;
  until first > last;
end;
 
begin
  assign(input,fi);reset(input);
  assign(output,fo);rewrite(output);
  readln(n,m); ;
  fillchar(a,sizeof(a),0);
  fillchar(free,sizeof(free),true);
  for i:=1 to m do
    begin
      readln(u,v);
      a[u,v]:=1;
      a[v,u]:=1;
    end;
    bfs(1);
    ok:=false;
    for i:=1 to n do
    if free[i] then begin writeln(i);ok:=true;end;
    if not ok then writeln(0);
  close(input);close(output);
end.
