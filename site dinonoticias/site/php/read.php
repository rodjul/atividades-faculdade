<?php
include "php/banco_conexao.php";
$resultado = mysqli_query($conexao, "SELECT * from usuarios") or die("Não foi possível executar a SQL:".mysqli_error($conexao));
if($resultado){
    while($row = mysqli_fetch_array($resultado) ){
        echo $row['nome']." - ".$row['nota']."<br/>";
    }
}
echo "<br/><a href='index.html'>Voltar</a>";
mysqli_close($conexao);
?>